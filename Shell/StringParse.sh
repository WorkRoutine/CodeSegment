#!/bin/bash
set -e

# ----------------------------------------
# This script is used to parsing different string
# Maintainer: Buddy Zhang <buddy.zhang@aliyun.com>

FullString="http://biscuitOS.org/Shell_string.sh"
echo "Full String: $FullString"
echo ""

# '#' deletes left's characters and stores right's characters
echo "Section 0"
var=${FullString#*//}
echo "$var"
echo ""

# '##' deletes right's characters and store left's characters
echo "Section 1"
var=${FullString##*/}
echo "$var"
echo ""

# '%' deletes right's characters and stores left's characters
echo "Section 2"
var=${FullString%/*}
echo "$var"
echo ""

# '%%' deletes right's characters and stores left's characters
echo "Section 3"
var=${FullString%%/*}
echo "$var"
echo ""

# Store specify character from left to right
echo "Section 4"
var=${FullString:4:7}
echo "$var"
echo ""

# Store specify characters from x to end
echo "Section 5"
var=${FullString:7}
echo "$var"
echo ""

# Store specify characters from end to X
echo "Section 6"
var=${FullString:0-29:9}
echo "$var"
echo ""

# Store specify characters that start end and end to end
echo "Section 7"
var=${FullString:0-7}
echo "$var"
echo ""
