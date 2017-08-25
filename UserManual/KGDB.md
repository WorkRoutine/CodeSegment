 
        ========== How to use KGDB to debug your kernel ==========
 
 It's useful for everyone who want to know the kernel how to work to debug
 kernel by one step,so I will introduce how to signal debug on your kernel.
 First,we should get an kernel that contains full-debug function.So we 
 should get the kernel source code and compile it,we can follow these step:
 -> Get the source code from "https://www.kernel.org/"
 -> When we get the source code,we will compile the code according your arch.
    For me,we use Raspberry Pi to build our development environment,so we
    use command like:
        make bcmrpi_defconfig
    When we configure the kernel before compile,we should set some options,
    we modify the .config directly,for example:
        vi .config
    Modify these opetions:
        CONFIG_KGDB=y
        CONFIG_KGDB_SERIAL_CONSOLE=y
        CONFIG_KGDB_KDB=y
        CONFIG_DEBUG_KERNEL=y
        CONFIG_DEBUG_INFO=y
        CONFIG_DEBUG_RODATA=n
        CONFIG_PANIC_TIMEOUT=5
        CONFIG_BOOTPARAM_SOFTLOCKUP_PANIC_VALUE=1
        CONFIG_FRAME_POINTER=y
        CONFIG_KALLSYMS=y
        CONFIG_KDB_KEYBOARD=y
        CONFIG_KDB_TEST=y
    And then,start compile,use command:
        make zImage modules dtbs
        make INSTALL_MOD_PATH=/SD/rootfs/lib/modules/ modules_install
        scripts/mkknling arch/arm/boot/zImage /SD/boot/kernel.img
    Note,"/SD" is dirent that you mount SD card.If you use device tree,
    you should update your device tree on board,you can use command:
        cp arch/arm/boot/dts/*.dtb /SD/boot/
        cp arch/arm/boot/dts/overlays/*.dtb* /SD/boot/overlays/
        cp arch/arm/boot/dts/overlay/README  /SD/boot/overlays/
    Now,we have been updated our kernel.
 -> Modify the uboot boot command line,add the kgdb argument into 
    command line to support debug kernel start-up.
    For Raspberry Pi,we can modify the /SD/boot/cmdline.txt,as:
        .... console=serial0,115200 console=tty1 ....
        .... kgdboc=ttyAMA0,115200 kgdbwait ....   
    If you want to use ethernet to connect kgdb,Pls modify:
        .... console=serial0,115200 console=tty1 ....
        .... kgdboe=ttyAMA0,115200 kgdbwait ....   
 -> Start debug,boot your board,and start-up vmlinux with arm-linux-gdb,as:
        arm-linux-gdb vmlinux
        target remote /dev/ttyUSB0
    Now,we can start single debug the kernel,gool luck!                                      
 More document,you can refer to:
    gdb user
       mannual: http://sourceware.org/gdb/current/onlinedocs/gdb/
    gdb
       internal: http://www.sourceware.org/gdb/onlinedocs/gdbint.html
    kgdb/kgdb official
       website: https://kgdb.wiki.kernel.org/
    kernel debug
       usage: http://www.kernel.org/doc/htmldocs/kgdb.html
    kdb in elinux.org
       http://elinux.org/KDB
    multi-threds debug in gdb
       http://www.ibm.com/developerworks/cn/linux/l-cn-gdbmp/
    KGDB.info
       http://www.kgdb.info/
