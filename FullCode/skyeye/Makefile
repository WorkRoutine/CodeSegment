CC=arm-linux-gnueabihf-gcc
LD=arm-linux-gnueabihf-ld
CFLAGS = -c -Wall -Wstrict-prototypes -Wno-trigraphs -O2 -pipe -g  
CFLAGS+= -march=armv4 -mtune=arm7tdmi 
LDFLAGS= -N -p -X -Thello.lds
    
LIB=
    
all: hello 

hello: start.o hello.o
	@$(LD) $(LDFLAGS)  start.o hello.o -o hello
	@arm-linux-gnueabihf-objdump -xS hello > hello.s
	@arm-linux-gnueabihf-readelf -a hello > hello.r
	@arm-linux-gnueabihf-nm hello > hello.n
	 
start.o:start.S
	@$(CC) $(CFLAGS) start.S	 
	
hello.o:hello.c
	@$(CC) $(CFLAGS) hello.c

PHONY: clean
clean:
	@rm -rf *.o *.elf *.gdb hello *.r *.n *.s



