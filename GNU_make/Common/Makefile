# ---------------------------------------
# Simple Makefile demo code 
# Maintainer: Buddy <buddy.zhang@aliyun.com>

CC := gcc
VPATH := src
CFLAGS := -g -I./include
OBJS := main.o
TARGET := Running
V :=

all: $(TARGET)

$(TARGET): $(OBJS)
	$(V)$(CC) $^ $(CFLAGS) -o $@
	$(V)rm *.o

main.o: main.c
	$(V)$(CC) $^ $(CFLAGS) -c -o $@

.PHONY: clean
clean:
	$(V)rm $(TARGET)
