# Tools
CROSS=arm-linux-gnueabihf
CC=${CROSS}-gcc
LD=${CROSS}-ld
OBJDUMP=${CROSS}-objdump
READELF=${CROSS}-readelf
NM=${CROSS}-nm

# Flags 
CFLAGS = -c -Wall -Wstrict-prototypes -Wno-trigraphs -O2 -pipe -g  
CFLAGS+= -march=armv4 -mtune=arm7tdmi 
LDFLAGS= -N -p -X -Tsimple.lds

# Target
TARGET=hello

# Objects
OBJS=sample.o simple.o
    
# library
LIB=
    

all: ${TARGET}

${TARGET}: ${OBJS}
	@$(LD) $(LDFLAGS)  ${OBJS} -o ${TARGET}
	@${OBJDUMP} -xS ${TARGET} > ${TARGET}.s
	@${READELF} -a ${TARGET} > ${TARGET}.r
	@${NM} ${TARGET} > ${TARGET}.n
	 
sample.o:sample.S
	@$(CC) $(CFLAGS) sample.S	 
	
simple.o:simple.c
	@$(CC) $(CFLAGS) simple.c

PHONY: clean
clean:
	@rm -rf *.o *.elf *.gdb ${TARGET} *.r *.n *.s



