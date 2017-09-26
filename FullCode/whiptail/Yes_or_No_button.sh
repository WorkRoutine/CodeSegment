#!/bin/bash

if (whiptail --title "Test Yes/No Box" --yes-button "Skittles" --no-button "M&M's" --yesno "Which do you like better?" 10 60) then
	echo "You choose Skittles Exit status was $?."
else
	echo "You choose M&M's. Exit status was $?."
fi
