# ---------------------------------------------
# BiscuitOS Configure System
# Maintainer: Buddy <buddy.zhang@aliyun.com>
#

CC=gcc
TARGET=BiscuitOS
V=

all: $(TARGET)

$(TARGET): BiscuitOS_Configure.c main.c
	$(V)$(CC) $^ -o $@

# Flex source code
BiscuitOS_Configure.c: BiscuitOS_Configure.l
	$(V)flex $<
	$(V)mv lex.yy.c $@

.PHONY: clean
clean:
	$(V)rm $(TARGET)
