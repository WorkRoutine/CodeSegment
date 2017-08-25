#!/bin/bash
# whiptail --title "" -yesno ""

if (whiptail --title "Test Yes/No Box" --yesno "Choose between Yes and No." 10 60) then
	echo "You choose Yes. Exit status was $?."
else
	echo "You choose No. Exit status was $?."
fi
