#!/bin/bash
set -e
# -----------------------------------
# Dialog: Check list dialog
# Maintainer: Buddy <buddy.zhang@aliyun.com>

dialog --backtitle "Checklist" --checklist "Option" 20 50 10 \
         Memory Memory_Size 1 Disk Disk_Size 2 
