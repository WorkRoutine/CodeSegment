#!/bin/bash
set -e
# -----------------------------------
# Dialog: Yes or No dialog
# Maintainer: Buddy <buddy.zhang@aliyun.com>

dialog --title "yes/no" --no-shadow --yesno \
       "Delete the file file?" 10 30
