#!/bin/bash
set -e

# ------------------------------------------------
# This script is uesed to connect wifi AP via command line
# Maintainer: Buddy Zhang <buddy.zhang@aliyun.com>
#
CONFIG_FILE=/etc/network/wpa_supplication.conf

clear
echo "=== OrangePi Wifi Configure ==="

if [ -f $CONFIG_FILE ]; then
    SSID=`cat $CONFIG_FILE | grep "ssid"`
    USER=${SSID#*=}
    read -p "$USER has exist! Do you want to connect?[Y/N] " SELECT
    if [ $SELECT = "Y" -o $SELECT = "y" ]; then
        # Connect wifi AP
        wpa_supplicant -Dnl80211 -iwlan0 -c$CONFIG_FILE &
        dhcpcd wlan0 & 
        exit 0
    fi
fi

echo ""
read -p "Please input AP name: " WIFI_AP
read -p "Please input passwd:  " WIFI_PSD
echo ""

# Create wifi configure
cat > "$CONFIG_FILE" <<EOF
ap_scan=1
fast_reauth=1
eapol_version=1
network={
    ssid="${WIFI_AP}"
    psk="${WIFI_PSD}"
    priority=1
}
EOF

# Connect wifi AP
wpa_supplicant -Dnl80211 -iwlan0 -c$CONFIG_FILE &
dhcpcd wlan0 & 
