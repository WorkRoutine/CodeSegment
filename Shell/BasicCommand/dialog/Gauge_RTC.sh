#!/bin/bash
set -e
# ------------------------------------
# Dialog: Gauge RT 
# Maintainer: Buddy <buddy.zhang@aliyun.com>

for i in {1..100}; do echo $i; done | \
    dialog --title "Installation pro" --gauge "installation" 10 30 10
