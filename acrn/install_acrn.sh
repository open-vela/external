#!/bin/bash
# This script is for installing ACRN via SSH

# Usage:
# ./install_acrn.sh $1 $2 $3 $4
# $1 is target SSH address, for example: openvela@0.0.0.0
# $2 is target SSH password, for example: 123
# $3 is target SSH port, for example: 22
# $4 is configuration directory path
# For example:
# Install to remote machine:
# ./install_acrn.sh openvela@0.0.0.0 123 22 acrn-config/rk-479/defconfig
# Install to local machine:
# ./install_acrn.sh mi@127.0.0.1 123 22 acrn-config/rk-479/defconfig

ramdisk_name="service_ramdisk.cpio"

ssh_address=$1
ssh_password=$2
ssh_port=$3
config_path=$4

ssh_ip=`echo $ssh_address | cut -d@ -f2`
board_config_path=${config_path%/*}

output_path=build/${config_path#*/}

kernel_pack=`ls build/*acrn-service-vm*.deb 2>/dev/null`
kernel_version=`echo ${kernel_pack} | grep -oP '(?<=linux-image-).*?(?=_)'`
ramdisk_pack=`ls ${output_path}/${ramdisk_name} 2>/dev/null`

ssh_pass="sshpass -p ${ssh_password}"
ssh_rexec="${ssh_pass} ssh ${ssh_address} -p${ssh_port}"
scp="${ssh_pass} scp -P ${ssh_port}"
remote_sudo="echo ${ssh_password} | sudo -S"

echo -e "\n\e[36m--------Test SSH to target...--------\n\e[\0m"
ssh-keygen -R "${ssh_ip}"
${ssh_rexec} "echo Target: if you see this, it means ssh connection is successful"

echo -e "\n\e[36m--------Copying ACRN Hypervisor packages to target...--------\n\e[\0m"
${scp} ${output_path}/acrn*.deb ${output_path}/grub*.deb ${output_path}/*acrn-board-inspector*.deb ${ssh_address}:/tmp/

if [ -n "${kernel_pack}" ]; then
    echo -e "\n\e[36m--------Copying ACRN Service VM Kernel packages to target...--------\n\e[\0m"
    echo -e "\n\e[36m--------ACRN Service VM Version ${kernel_version}--------\n\e[\0m"
    ${scp} build/*acrn-service-vm*.deb ${ssh_address}:/tmp/
fi

echo -e "\n\e[36m--------Installing ACRN Packages to target...--------\n\e[\0m"
${ssh_rexec} "${remote_sudo} apt remove -y acrn\* \*acrn-service-vm\*"
${ssh_rexec} "${remote_sudo} apt install -y /tmp/*.deb --allow-downgrades"

if [ -n "${ramdisk_pack}" ]; then
    # Install RAMDisk to target and update GRUB
    echo -e "\n\e[36m--------Installing RAMDisk to target...--------\n\e[\0m"
    ${scp} ${output_path}/${ramdisk_name} ${ssh_address}:/tmp/
    ${ssh_rexec} "${remote_sudo} cp /tmp/${ramdisk_name} /boot/initrd.img-${kernel_version}"

    echo -e "\n\e[36m--------Modifying GRUB on target...--------\n\e[\0m"
    ${ssh_rexec} "${remote_sudo} update-grub"
    ${ssh_rexec} "${remote_sudo} sed -i '/Ubuntu with ACRN hypervisor, with Linux 6.1.80-acrn-*/a\        set next_entry=6\n\tsave_env next_entry' /boot/grub/grub.cfg"
    ${ssh_rexec} "${remote_sudo} sed -i '/Windows/a\        set next_entry=5\n\tsave_env next_entry' /boot/grub/grub.cfg"
else
    # Directly Install to target rootfs.
    echo -e "\n\e[36m--------Copying ACRN Launch Scripts to target...--------\n\e[\0m"
    ${scp} ${output_path}/*.sh ${ssh_address}:~

    echo -e "\n\e[36m--------Copying NuttX to target...--------\n\e[\0m"
    ${scp} ../../nuttx/boot.iso ${ssh_address}:~

    echo -e "\n\e[36m--------Copying ACRN OVMF BIOS to target...--------\n\e[\0m"
    ${scp} ${output_path}/*.fd ${ssh_address}:/tmp/

    echo -e "\n\e[36m--------Installing Launch Scripts and OVMF BIOS to target...--------\n\e[\0m"
    ${ssh_rexec} "chmod +x ~/*.sh"
    ${ssh_rexec} "${remote_sudo} cp /tmp/*.fd /usr/share/acrn/bios/"

    echo -e "\n\e[36m--------Setting up ACRN Network configuration on target...--------\n\e[\0m"
    ${ssh_rexec} "${remote_sudo} cp /usr/share/doc/acrnd/examples/* /etc/systemd/network"

    echo -e "\n\e[36m--------Modifying GRUB on target...--------\n\e[\0m"
    ${ssh_rexec} "${remote_sudo} update-grub"
    ${ssh_rexec} "${remote_sudo} sed -i '/Ubuntu with ACRN hypervisor, with Linux 6.1.80-acrn-*/a\        set next_entry=5\n\tsave_env next_entry' /boot/grub/grub.cfg"
fi
