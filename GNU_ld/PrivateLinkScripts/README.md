Ld scripts
-------------------------------------------------

* Machine: Ubuntu16.06/64bit
* ld: GNU ld (GNU Binutils for Ubuntu) 2.26.1

### default ld scripts

Use default ld scripts
```
32bit:
gcc TinyHelloWorld.c -m32 -c -fno-builtin -o TinyHelloWorld.o
ld TinyHelloWorld.o -static -m elf_i386 -e nomain -o TinyRunning

64bit:
gcc TinyHelloWorld.c -c -fno-builtin -o TinyHelloWorld.o
ld TinyHelloWorld.o -static -e nomain -o TinyRunning
```
-static: Use static library no dynamic library

-e: Set entry for program

-m: Use specify platform, elf_i386 is 32bit and elf_x86_64 is 64bit

### Private ld scripts

Use private ld scripts, we should crate private ld scripts, as follow:
```
ENTRY(nomain)

SECTIONS
{
	. = 0x08048000 + SIZEOF_HEADERS;
			
	tinytext : { *(.text) *(.data) *(.rodata) }

	/DISCARD/ : { *(.comment) }
}
```
"." represents current virtual address. 
On Linux, the start virtual address of user space program is
"0x08048000", and we should set current virtual address is start of 
text section virtual address, so we adjust virtual via adding 
"SIZEOF_HEADERS".

"tinytext" make all "text section", "data section" and "rodata section" 
add into "tinytext" section.

"/DISCARD/" will discard all "comment section".

Using private ld scripts
```
32bit:
gcc TinyHelloWorld.c -m32 -fno-builtin -c -o TinyHelloWorld.o
ld TinyHelloWorld.o -m elf_i386 -static -T private_ld_scripts.lds -o TinyRunning

64bit:
gcc TinyHelloWorld.c -fno-builtin -c -o TinyHelloWorld.o
ld TinyHelloWorld.o -static -T private_ld_scripts.lds -o TinyRunning
```


