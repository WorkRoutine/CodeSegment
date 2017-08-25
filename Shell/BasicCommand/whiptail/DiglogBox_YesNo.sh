#!/bin/bash
set -e
# ------------------------------------
# Diglog box to set yes or no
# Maintainer: Buddy <buddy.zhang@aliyun.com>

if (whiptail --title "Yes/No Diglog Box" --yesno "Choose between Yes and No." 10 60) then
	echo "You choose Yes. Exit status was $?."
else
	echo "You choose No. Exit status was $?."
fi
