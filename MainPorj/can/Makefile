CFLAGS = -g -O0 -Wall -fno-strict-aliasing -I./
LDFLAGS += -lpthread


SRCS =  main.c can.c sent.c signal.c receive.c command.c

OBJS=$(subst .c,.o,$(SRCS))


%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

cantools: $(OBJS) 
	@rm -f $@
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

all: cantools

clean:
	$(RM) *.o cantools
