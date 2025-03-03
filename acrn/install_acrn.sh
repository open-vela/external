#!/bin/bash
# This script is for installing ACRN
# Usage:
# ./install_acrn.sh $1 $2 $3 $4 [$5] [$6]
# $1 is target ssh address, for example: openvela@0.0.0.0
# $2 is target ssh password, for example: 123
# $3 is target ssh port, for example: 22
# $4 is configuration directory path
# $5 [y] skips ACRN Service VM kernel installing
# $6 [y] skips RAMDisk installing
# For example:
# ./install_acrn.sh openvela@0.0.0.0 123 22 acrn-config/rk-479/defconfig

ssh_address=$1
ssh_password=$2
ssh_port=$3
config_path=$4
no_kernel=$5
no_ramdisk=$6
ssh_ip=`echo $ssh_address | cut -d@ -f2`
board_config_path=${config_path%/*}
ramdisk_name="service_ramdisk.cpio"

ssh_pass="sshpass -p ${ssh_password}"
ssh_rexec="${ssh_pass} ssh ${ssh_address} -p${ssh_port}"
scp="${ssh_pass} scp -P ${ssh_port}"
remote_sudo="echo ${ssh_password} | sudo -S"

echo "--------Test ssh to target...--------"
ssh-keygen -R "${ssh_ip}"
${ssh_rexec} "echo Target: if you see this, it means ssh connection is successful"

echo "--------Copying ACRN Hypervisor packages to target...--------"
${scp} ./acrn*.deb ./grub*.deb ./*acrn-service-vm*.deb ${ssh_address}:/tmp
echo "--------Copying ACRN Service VM kernel packages to target...--------"
if [ ! "${no_kernel}" = "y" ]; then
    ${scp} ./*acrn-service-vm*.deb ${ssh_address}:/tmp
fi
echo "--------Copying ACRN Launch Scripts to target...--------"
${scp} ./${config_path}/*.sh ${ssh_address}:~
echo "--------Copying ACRN OVMF BIOS to target...--------"
${scp} ./${board_config_path}/*.fd ${ssh_address}:/tmp

echo "--------Installing ACRN Packages, Launch Scripts and OVMF BIOS to target...--------"
${ssh_rexec} "${remote_sudo} apt remove -y acrn* *service-vm*"
${ssh_rexec} "${remote_sudo} apt install -y /tmp/*.deb"
${ssh_rexec} "chmod +x ~/*.sh"
${ssh_rexec} "${remote_sudo} cp /tmp/*.fd /usr/share/acrn/bios/"

echo "--------Setting up ACRN Network configuration on target...--------"
${ssh_rexec} "${remote_sudo} cp /usr/share/doc/acrnd/examples/* /etc/systemd/network"

# Install RAMDisk to target and update GRUB
if [ ! "${no_ramdisk}" = "y" ]; then
    echo "--------Installing RAMDisk to target...--------"
    ${scp} ./${ramdisk_name} ${ssh_address}:/tmp/
    ${ssh_rexec} "${remote_sudo} cp /tmp/${ramdisk_name} /boot/initrd.img-6.1.80-acrn-*"

    echo "--------Updating GRUB on target...--------"
    ${ssh_rexec} "${remote_sudo} update-grub"
    ${ssh_rexec} "${remote_sudo} sed -i '/Ubuntu with ACRN hypervisor, with Linux 6.1.80-acrn-*/a\        set next_entry=6\n\tsave_env next_entry' /boot/grub/grub.cfg"
    ${ssh_rexec} "${remote_sudo} sed -i '/Windows/a\        set next_entry=5\n\tsave_env next_entry' /boot/grub/grub.cfg"
fi
