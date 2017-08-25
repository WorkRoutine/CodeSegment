#!/bin/bash
set -e
# ----------------------------------
# CheckList
# Maintainer: Buddy <buddy.zhang@aliyun.com>

DISTROS=$(whiptail --title "CheckList" \
                   --checklist  \
				   "What is the Linux distro of your choice?" 15 60 4 \
				   "Debian" "Venerable Debian" ON \
				   "Ubuntu" "Popular Ubuntu" OFF \
				   "Centos" "Stable CentOS" OFF \
				   "Mint" "Rising Star Mint" OFF \
				   3>&1 1>&2 2>&3)

exitstatus=$?
if [ ${exitstatus} = 0 ]; then
	echo "The chosen is ${DISTROS}"
else
	echo "Bad chose"
fi
