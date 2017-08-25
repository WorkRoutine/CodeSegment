#!/bin/bash
SECTORS=32
HEADS=16
DRIVE=$1
SIZE=`fdisk -l $DRIVE | grep Disk | awk '{print $5}'`
CYLINDERS=`echo $SIZE/${SECTORS}/${HEADS}/512 | bc`

# ----------------------------------
# Bootloader partitions
# ----------------------------------
bootloader_first_cylinders=0
bootloader_cylinders=2
bootloader_ID=
bootloader_bootable=

# ----------------------------------
# Rootfs partitions
# ----------------------------------
rootfs_first_cylinders=
rootfs_cylinders=
rootfs_ID=
rootfs_bootable=


# --------------------------------------------------------------
# sfdisk reads lines of the form:
#    <start> <size> <id> <bootable> <c,h,s> <c,h,s>
# --------------------------------------------------------------
sfdisk -H ${HEADS} -S ${SECTORS} -C ${CYLINDERS} ${DRIVE} << EOF
${bootloader_first_cylinders},${bootloader_cylinders}, \
                   ${bootloader_ID},${bootloader_bootable}
${rootfs_first_cylinders},${rootfs_cylinders}, \
                   ${rootfs_ID},${rootfs_bootable}
EOF
