#!/bin/bash
#SIZE=$(stat -c %s t.sh)
#echo "SIZE $SIZE"

# Full path of src
FILE="ArchLinux_Desktop_Xfce4_A64_Win_V0_11.img"
SRC_PATH="/home/orange/OPEN_SOURCE/OrangePi_A64SDK/Image/ArchLinux/"
SRC="${SRC_PATH}/${FILE}"
# Full path of dest
DEST_PATH="/home/orange/tmp"
DEST="${DEST_PATH}/${FILE}"
FULL_SIZE=$(stat -c %s ${SRC_PATH}/${FILE})
cp $SRC $DEST && sync &

{
	for ((i = 0; i < 100; )); do
		sleep 1
		SIZE=$(stat -c %s ${DEST})
		i=$[ SIZE * 100 / FULL_SIZE ]
		echo $i
	done
} | whiptail --gauge "Please wait while installing" 6 60 0
