#!/bin/bash
set -e
# ------------------------------------
# Menu list
# Maintainer: Buddy <buddy.zhang@aliyun.com>

OPTION=$(whiptail --title "MenuList" \
				  --menu "Choose your option" \
				  15 60 4 \
				  "1" "Girl" \
				  "2" "Women" \
				  "3" "Young Girl" \
				  "4" "Old women" 3>&1 1>&2 2>&3)

exitstatus=$?
if [ ${exitstatus} = 0 ]; then
	echo "Your chosen option $OPTION"
else
	echo "You chose Cancel."
fi
