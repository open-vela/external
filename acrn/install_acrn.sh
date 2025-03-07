#!/bin/bash
# This script is for installing ACRN via SSH

# Usage:
# ./install_acrn.sh $1 $2 $3 $4 [$5] [$6]
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

kernel_pack=`ls *acrn-service-vm*.deb`
kernel_version=`echo ${kernel_pack} | grep -oP '(?<=linux-image-).*?(?=_)'`
ramdisk_pack=`ls ${ramdisk_name}`

ssh_pass="sshpass -p ${ssh_password}"
ssh_rexec="${ssh_pass} ssh ${ssh_address} -p${ssh_port}"
scp="${ssh_pass} scp -P ${ssh_port}"
remote_sudo="echo ${ssh_password} | sudo -S"

echo -e "\n--------Test SSH to target...--------\n"
ssh-keygen -R "${ssh_ip}"
${ssh_rexec} "echo Target: if you see this, it means ssh connection is successful"

echo -e "\n--------Copying ACRN Hypervisor packages to target...--------\n"
${scp} ./acrn*.deb ./grub*.deb ./*acrn-service-vm*.deb ${ssh_address}:/tmp/

if [ -n "${kernel_pack}" ]; then
    echo -e "\n--------Copying ACRN Service VM Kernel packages to target...--------\n"
    echo -e "\n--------ACRN Service VM Version ${kernel_version}--------\n"
    ${scp} ./*acrn-service-vm*.deb ${ssh_address}:/tmp/
fi

echo -e "\n--------Installing ACRN Packages to target...--------\n"
${ssh_rexec} "${remote_sudo} apt remove -y acrn* *service-vm*"
${ssh_rexec} "${remote_sudo} apt install -y /tmp/*.deb --allow-downgrades"

if [ -n "${ramdisk_pack}" ]; then
    # Install RAMDisk to target and update GRUB
    echo -e "\n--------Installing RAMDisk to target...--------\n"
    ${scp} ./${ramdisk_name} ${ssh_address}:/tmp/
    ${ssh_rexec} "${remote_sudo} cp /tmp/${ramdisk_name} /boot/initrd.img-${kernel_version}"

    echo -e "\n--------Modifying GRUB on target...--------\n"
    ${ssh_rexec} "${remote_sudo} update-grub"
    ${ssh_rexec} "${remote_sudo} sed -i '/Ubuntu with ACRN hypervisor, with Linux 6.1.80-acrn-*/a\        set next_entry=6\n\tsave_env next_entry' /boot/grub/grub.cfg"
    ${ssh_rexec} "${remote_sudo} sed -i '/Windows/a\        set next_entry=5\n\tsave_env next_entry' /boot/grub/grub.cfg"
else
    # Directly Install to target rootfs.
    echo -e "\n--------Copying ACRN Launch Scripts to target...--------\n"
    ${scp} ./${config_path}/*.sh ${ssh_address}:~

    echo -e "\n--------Copying NuttX to target...--------\n"
    ${scp} ../../nuttx/boot.iso ${ssh_address}:~

    echo -e "\n--------Copying ACRN OVMF BIOS to target...--------\n"
    ${scp} ./${board_config_path}/*.fd ${ssh_address}:/tmp/

    echo -e "\n--------Installing Launch Scripts and OVMF BIOS to target...--------\n"
    ${ssh_rexec} "chmod +x ~/*.sh"
    ${ssh_rexec} "${remote_sudo} cp /tmp/*.fd /usr/share/acrn/bios/"

    echo -e "\n--------Setting up ACRN Network configuration on target...--------\n"
    ${ssh_rexec} "${remote_sudo} cp /usr/share/doc/acrnd/examples/* /etc/systemd/network"
fi
