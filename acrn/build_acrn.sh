#!/bin/bash
# This script is for building ACRN
# Usage:
# ./build_acrn.sh $1 [$2] [$3]
# $1 is configuration directory path
# $2 [y] skips ACRN Service VM kernel compile
# $3 [y] skips RAMDisk compile
# For example:
# ./build_acrn.sh acrn-config/rk-479/defconfig

config_path=$1
no_kernel=$2
no_ramdisk=$3

board_config_path=${config_path%/*}

echo "--------Cleaning the directory--------"
./clean_acrn.sh

echo "--------Compiling ACRN Hypervisor--------"
cd ./acrn-hypervisor
if [ ! -n "${config_path}" ]; then
    # Only Compile ACRN Board Configurator if no config directory is given.
    echo "--------Only Compile ACRN Board Configurator--------"
    debian/debian_build.sh clean && debian/debian_build.sh board_inspector
else
    debian/debian_build.sh clean && debian/debian_build.sh -c ../${config_path}
fi
cd ..

echo "--------Compiling ACRN Kernel--------"
if [ ! "${no_kernel}" = "y" ]; then
    cd ./acrn-kernel
    cp kernel_config_service_vm .config
    make olddefconfig
    make -j $(nproc) deb-pkg
    cd ..
fi

# Packing RAMDisk
if [ ! "${no_ramdisk}" = "y" ]; then
    echo "--------Generating RAMDisk--------"

    chmod +x ${config_path}/*.sh

    echo "--------Copy launch scripts, Vela ISO and OVMF BIOS to RAMDisk--------"
    cp ${config_path}/*.sh service_ramdisk/jammy-base-amd64/home/mi
    cp ../../nuttx/boot.iso service_ramdisk/jammy-base-amd64/home/mi
    cp ${board_config_path}/*.fd service_ramdisk/jammy-base-amd64/usr/share/acrn/bios/

    echo "--------Copy interfaces and rc.local to RAMDisk--------"
    cp ${config_path}/ramdisk/interfaces service_ramdisk/jammy-base-amd64/etc/network/interfaces
    cp ${config_path}/ramdisk/rc.local service_ramdisk/jammy-base-amd64/etc/rc.local
    chmod +x service_ramdisk/jammy-base-amd64/etc/rc.local

    echo "--------Packing RAMDisk--------"
    cd service_ramdisk/jammy-base-amd64
    find . | cpio -o -H newc > ../../service_ramdisk.cpio
fi
