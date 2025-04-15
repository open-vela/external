#!/bin/bash
# This script is for building ACRN Hyervisor, ACRN Service VM kernel and RAMDisk

# Usage:
# ./build_acrn.sh $1 [$2]
# $1 is configuration directory path
# $2 [y] forace compile ACRN Service VM kernel
# For example:
# ./build_acrn.sh acrn-config/rk-479/defconfig
# Force compile ACRN Kernel compile:
# ./build_acrn.sh acrn-config/rk-479/defconfig y

config_path=$1
force_compile_kernel=$2

board_config_path=${config_path%/*}


output_path=build/${config_path#*/}

echo -e "\n\e[36m--------Cleaning the directory-------\n\e[\0m"
rm -rf ${output_path}
mkdir -p ${output_path}
./clean_acrn.sh

echo -e "\n\e[36m--------Compiling ACRN Hypervisor-------\n\e[\0m"

# Overriding `50-eth.network`, the ACRN netbridge configuration file.
cp ${config_path}/50-eth.network ./acrn-hypervisor/misc/packaging/50-eth.network

# Compiling ACRN Hypervisor.
cd ./acrn-hypervisor
if [ ! -n "${config_path}" ]; then
    # Only Compile ACRN Board Configurator if no config directory is given.
    echo -e "\n\e[36m--------Only Compile ACRN Board Configurator-------\n\e[\0m"
    debian/debian_build.sh clean && debian/debian_build.sh board_inspector
else
    debian/debian_build.sh clean && debian/debian_build.sh -c ../${config_path}
fi
cd ..
mv ./acrn*.deb ./grub*.deb ./*acrn-board-inspector*.deb ${output_path}
cp ${config_path}/*.sh ${output_path}
cp ${board_config_path}/*.fd ${output_path}

# Check if ACRN Service VM Kernel is already built.
kernel_pack=`ls build/*acrn-service-vm*.deb 2>/dev/null`
if [ "${force_compile_kernel}" = "y" ] || [ ! -n "${kernel_pack}" ]; then
    echo -e "\n\e[36m--------Compiling ACRN Service VM Kernel-------\n\e[\0m"
    cd ./acrn-kernel
    make distclean -j $(nproc)
    cp kernel_config_service_vm .config
    make olddefconfig
    make -j $(nproc) deb-pkg
    cd ..
    mv *acrn-service-vm*.deb ./build
fi

# Packing RAMDisk only when ramdisk directory exists.
if [ -d "${config_path}/ramdisk" ]; then
    echo -e "\n\e[36m--------Start generating RAMDisk-------\n\e[\0m"

    chmod +x ${config_path}/*.sh

    echo -e "\n\e[36m--------Copy kernel modules to RAMDisk-------\n\e[\0m"
    mkdir -p service_ramdisk/jammy-base-amd64/lib/modules/
    cp -r acrn-kernel/debian/linux-image/lib/modules/* service_ramdisk/jammy-base-amd64/lib/modules/

    echo -e "\n\e[36m--------Copy launch scripts, Vela ISO and OVMF BIOS to RAMDisk-------\n\e[\0m"
    cp ${config_path}/*.sh service_ramdisk/jammy-base-amd64/home/mi
    cp ../../nuttx/boot.iso service_ramdisk/jammy-base-amd64/home/mi
    cp ${board_config_path}/*.fd service_ramdisk/jammy-base-amd64/usr/share/acrn/bios/

    echo -e "\n\e[36m--------Copy interfaces and rc.local to RAMDisk-------\n\e[\0m"
    cp ${config_path}/ramdisk/interfaces service_ramdisk/jammy-base-amd64/etc/network/interfaces
    cp ${config_path}/ramdisk/rc.local service_ramdisk/jammy-base-amd64/etc/rc.local
    chmod +x service_ramdisk/jammy-base-amd64/etc/rc.local

    echo -e "\n\e[36m--------Packing RAMDisk-------\n\e[\0m"
    cd service_ramdisk/jammy-base-amd64
    find . | cpio -o -H newc > ../../service_ramdisk.cpio
    cd ../../

    mv service_ramdisk.cpio ${output_path}
fi

# Clean the directory
./clean_acrn.sh