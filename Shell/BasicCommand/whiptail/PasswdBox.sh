#!/bin/bash
set -e
# ----------------------------------------
# PasswdBox
# Maintainer: Buddy <buddy.zhang@aliyun.com>

PASSWD=$(whiptail --title "PasswdBox" \
				  --passwordbox "Enter your password and choose Ok to contine."\
				  10 60 3>&1 1>&2 2>&3)

exitstatus=$?
if [ ${exitstatus} = 0 ]; then
	echo "Your passwd is ${PASSWD}"
else
	echo "You choose Cancel"
fi
