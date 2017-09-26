#!/bin/bash

# whiptail --title "" --passwordbox ""

PASSWD=$(whiptail --title "Password Box" --passwordbox "Enter your password and choose OK to continue." 10 60 3>&1 1>&2 2>&3)

exitstatus=$?
if [ $exitstatus = 0 ]; then
	echo "Your passwd is:" $PASSWD
else
	echo "You choose Cancle"
fi
