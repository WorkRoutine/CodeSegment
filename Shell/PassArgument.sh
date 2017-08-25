#!/bin/bash
set -e

# This script is used to pass argument on shell
# Maintainer: Buddy Zhang <buddy.zhang@aliyun.com>

# Pass argument on function
function Fun_argument()
{
    echo "Argument1: $1"
    echo "Argument2: $2"    
}

Fun_argument "Argment0" "Argument1"

# Pass argment via export
PLATFORM="Allwinner"
export PLATFORM

# Get argment from other shell
if [ ! -z $1 ]; then
    MACHINE=$1
else
    MACHINE="ARM"
fi
# Pass argument to Argument.sh
./_Argument.sh $MACHINE

# Pass argument via .
. _parse.sh

echo "MACH $MACH"
