 How to use qemu-system-arm to debug your kernel
 Qemu is useful tools to simulate the different arch-machine,like ARM-cortexX.
 This document will tell you how to use this tools to debug your kernel,it's 
 useful for everyone who want to know the kernel how to work to learn 
 Linux kernel.So we should follow these step to build all.
 -> Above all to install the development environment on your PC.Pls get 
    the source code of qeme from web,then configure and install it,we 
    can use command:
        cd qemu_source_code/
        ./configure
        make 
        make install
 -> Now the qemu has installed on your computer.Now we should confirm the 
    arch-machine that qemu-system-arm will support,we can use command:
        qemu-system-arm -machine help
    For this command,the qemu-system-arm will list the support machine.
    For me,I use Raspberry,so the qemu-system-arm supports RaspberryPi2.
 -> Then we will prepare the kernel image.Download the kernel source code
    from web,and configure as RaspberryPi2.finally compile the code and 
    get the zImage,we can use command:
        cd kernel/
        make bcm2709_defconfig
        make zImage
