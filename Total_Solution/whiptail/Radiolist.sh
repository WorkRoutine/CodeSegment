#!/bin/bash

# whiptail --title "" -radiolist "" [] ...

DISTROS=$(whiptail --title "Test Checklist Dialog" --radiolist \
	"What is the Linux Distro of your choice?" 15 60 4 \
	"Debian" "Venerable Debian" ON \
	"Ubuntu" "Popular Ubuntu" OFF \
	"Centos" "Stable CentOS" OFF \
	"mint" "Rising Star Mint" OFF \
	3>&1 1>&2 2>&3)

exitstatus=$?

if [ $exitstatus = 0 ]; then
	echo "The choose distro is:" $DISTROS
else
	echo "You choose Cancel"
fi
