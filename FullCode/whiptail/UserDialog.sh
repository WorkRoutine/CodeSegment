#!/bin/bash

# whiptail --title "" -checklist "" [] ..

DISTROS=$(whiptail --title "Checklist Dialog" --checklist \
	"Choose preferred Linux distros" 15 60 4 \
	"debian" "Venerable Debian" ON  \
	"ubuntu" "Popular Ubuntu" OFF \
	"centos" "Stable CentOS" ON \
	"mint" "Rising star Mint" OFF \
	3>&1 1>2& 2>&3)

exitstatus=$?
if [ $exitstatus = 0 ]; then
	echo "Your favorite distro are:" $DISTROS
else
	echo "You choose Cancel"
fi
