#!/bin/bash
set -e
# -----------------------------------
# Dialog: Form dialog
# Maintainer: Buddy <buddy.zhang@aliyun.com>

dialog --title "Form" \
       --form "Please input the infomation of new user:" 12 40 4  \
       "Username:" 1  1 "" 1  15  15  0  \
       "Full name:" 2  1 "" 2  15  15  0  \
       "Home Dir:" 3  1 "" 3  15  15  0  \
       "Shell:"    4   1 "" 4  15  15  0

