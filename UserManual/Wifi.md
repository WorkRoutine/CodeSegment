       
         ======== How to use command to connect wifi ========

 When you want to use wifi to connet internet with termial,we can use
 "ifconfig" ,"iwlist" and "iwconfig" to connect internel.It' useful for
 connecting internet with wifi to follow these step:
 -> Use "ifconfig" to check the internet device that can use.
		 ifconfig
 -> We can find the wifi device via "ifconfig",and the name of 
	device is "wlanx".Then use "iwlist" to scan the wifi AP
         iwlist wlanx scan | grep ESSID
    And we will get the name of Wifi AP.
 -> Now,we should add the information for connect,use command:
         wpa_passphrase ESSID PASSWD > \
                       /etc/wpa_supplicant/wpa_supplicant.conf
         wpa_supplicant -Dnl80211 -iwlan0 \
                       -c/etc/wpa_supplicant/wpa_supplicant.conf
    Note,ESSID is name of Wifi AP and PASSWD the passwd for Wifi AP.
 -> Finally,we should set auto get IP with dhcp,like:
         dhclient wlan0
