#!/bin/bash
set -e
# ----------------------------------------
# Button for yes or no
# Maintainer: Buddy <buddy.zhang@liyun.com>

if (whiptail --title "Yes/No Box" --yes-button "Skittles" --no-button "MM" --yesno "Whichi do you like better?" 10 60) then
	echo "You choose Skittles"
else
	echo "You choose MM"
fi
