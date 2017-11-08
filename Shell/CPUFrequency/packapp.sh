#!/bin/sh

# need 7z, ubuntu apt-get install pzip-full

if [ ! -d myapp ];then
	mkdir myapp
	echo "#!/bin/sh" >myapp/start
	echo "echo 'hello world'" >>myapp/start
	chmod 755 myapp/start
fi

if [ -d myapp ];then
	rm -fr myapp.zip
	cd myapp && chmod 755 start && 7z a -tzip -p"zduqlqj=##fdqqrw#zulwh"  ../myapp.zip * && cd ..
else
	echo "no found myapp, mkdir myapp"
fi


