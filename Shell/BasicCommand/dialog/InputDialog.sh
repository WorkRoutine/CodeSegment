#!/bin/bash
set -e
# -----------------------------------
# Dialog: Input dialog
# Maintainer: Buddy <buddy.zhang@aliyun.com>

dialog --title "Input your name" \
       --inputbox "Please input your name:" 10 30 2> .tmp.txt

rm .tmp.txt
