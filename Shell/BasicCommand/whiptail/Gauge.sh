#!/bin/bash
set -e
# -----------------------------------------
# Gauge
# Maintainer: Buddy <buddy.zhang@liyun.com>

{
	for ((i = 0; i < 100; i+= 1)); do
		sleep .100
		echo ${i}
	done
} | whiptail --gauge "Please wait while installing" 6 60 0
