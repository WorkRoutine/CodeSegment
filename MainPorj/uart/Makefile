CFLAGS = -g -O0 -Wall -fno-strict-aliasing -I./

SRCS = command.c signal.c uart.c main.c

OBJS=$(subst .c,.o,$(SRCS))


%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

uart2: $(OBJS) 
	@rm -f $@
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

all: uart2

clean:
	$(RM) *.o uart2
