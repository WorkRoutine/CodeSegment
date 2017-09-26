#!/bin/bash

# whiptail --titile "
# " -menu ""

OPTION=$(whiptail --title "Menu Dialog" --menu "Choose your option" 15 60 4 "1"  "OrangePi One" "2"  "OrangePi A64" "3"	 "OrangePi H5" "4"	 "OrangePi Lite" 3>&1 1>&2 2>&3)

exitstatus=$?

if [ $exitstatus = 0 ]; then
	echo "Your choose option:" $OPTION
else
	echo "You choose Cancel."
fi
