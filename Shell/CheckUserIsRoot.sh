#!/bin/bash
set -e

# Check current is root

if [ "$(id -u)" != "0" ]; then
    echo "Current user is not root!"
else
    echo "Current user is root!"
fi
