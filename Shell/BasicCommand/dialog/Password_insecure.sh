#!/bin/bash
set -e
# -----------------------------------
# Dialog: Password dialog
# Maintainer: Buddy <buddy.zhang@aliyun.com>

dialog --title "Password" --insecure --passwordbox \
       "Delete the file file?" 10 30
