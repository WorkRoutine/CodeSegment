#!/bin/bash

# whiptail --title "" --inputbox ""

PET=$(whiptail --title "Test Free-form input Box" --inputbox "What is your pet's name?" 10 60 Wigglebutt 3>&1 1>&2 2>&3)

exitstatus=$?

if [ $exitstatus = 0 ]; then
	echo "Your pet name is:" $PET
else
	echo "You choose Cancel"
fi
