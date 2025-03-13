#!/bin/bash

# Clean ACRN Files
rm -f *.deb *.gz *.zip *.ddeb
rm -f *.buildinfo *.changes *.dsc

# Clean RAMDisk
rm -f *.cpio
rm -f service_ramdisk/jammy-base-amd64/home/mi/*
rm -rf service_ramdisk/jammy-base-amd64/lib/modules
echo "exit 0" > service_ramdisk/jammy-base-amd64/etc/rc.local