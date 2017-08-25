Hello World
---------------------------------------------

* Platform: Ubuntu16.06/64bit
* gcc: 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.4)
* as: 2.26.1 (x86_64-linux-gnu)
* ld: GNU ld (GNU Binutils for Ubuntu) 2.26.1



* Preprocessing

```
64bit:
gcc hello_world.c -E -o hello_world.i

32bit:
gcc hello_world.c -m32 -E -o hello_world.i
```

* Compile

```
64bit:
gcc hello_world.c -S -o hello_world.s

32bit:
gcc hello_world.c -m32 -S -o hello_world.s
```

* Preprocessing & Compile

```
/usr/lib/gcc/x86_64-linux-gnu/5/cc1 hello_world.c 
```

* Assembly

```
64bit:
gcc hello_world.c -c -o hello_world.o
or
as hello_world.s -o hello_world.o

32bit:
gcc hello_world.c -m32 -c -o hello_world.o
or
as hello_world.s --32 -o hello_world.o
```

* Read object file

```
readelf hello_world.o
objdump -ht -s -d hello_world.o
size hello_world.o
```

* Linker

```
64bit:
gcc hello_world.o -o a.out
or
ld -static /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/c
rti.o /usr/lib/gcc/x86_64-linux-gnu/5.4.0/crtbeginT.o -L/usr/lib/gcc/x86_64-linux-gnu/5.4.0 -L/usr/lib -L/lib hello_world.o --start-group -lgcc -lgcc_eh -lc --end-group /usr/lib/gcc/x86_64-linux-gnu/5.4.0/crtend.o /usr/lib/x86_64-linux-gnu/crtn.o

32bit:
gcc hello_wrold.o -m32 -o a.out
or
ld -m elf_i386 -e main -static /usr/lib32/crt1.o /usr/lib32/crti.o /usr/lib/gcc
/x86_64-linux-gnu/5.4.0/x32/crtbeginT.o -L/usr/lib/gcc/x86_64-linux-gnu/5.4.0 -L/usr/lib32/ -L/lib32/ hello_world.o --start-group -lgcc -lgcc_eh -lc --end-group /usr/lib/gcc/x86_64-linux-gnu/5.4.0/x32/crtend.o /usr/lib32/crtn.o
or 
ld hello_world.o -e main -m elf_i386 -o a.out 
```

User private linker scripts
```
ld -T link.scripts
```

* Binary

Create a binary, such as Image,MP3 and Book and so on
  ```
32bit:
objcopy -I binary -O elf32-i386 -B i386 SelfSection.txt SelfSection.o
gcc hello_world.c SelfSection.o -m32 -o a.out
objdump -s -d a.out

  ```

* ELF

ELF header
```
readelf -h hello_world.o
```

ELF section table
```
readelf -S hello_world.o
```

ELF symbol table
```
nm hello_world.o
readelf -s hello_world.o
```

* Static library

Check static library
```
ar -t libc.a
```

Check symbol from static library
```
objdump -t libc.a
```

Check full ld file
```
gcc -static --verbose -fno-builtin -m32 hello_world.c
```
