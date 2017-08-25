TARGET="clean"
CC=gcc
FLAGS=-g -o

include tmp/Makefile

OBJ=main.o kbd.o insert.o

${TARGET}:${OBJ}
	@${CC} -o ${TARGET} ${OBJ}
	@rm *.o

${OBJ}:defs.h
kbd.o:command.h
insert.o:buffer.h

.PHONY: clean
clean:
	@rm ${TARGET}
