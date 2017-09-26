OBJS := hello_world.o shared_a.o hello_world.o
CC := gcc

OBJECTS := hello_world.c

#VPATH := src  
vpath %.c src
#vpath %.h include

.PHONY: all
all: hello Version

.PHONY: Version
Version:
	@echo "Version2.0"

#$(OBJECTS): %.o: %.c
#	$(CC) $< -c -o $@

hello: $(OBJS)
	@echo "We need update:    $?"
	@echo "The request file:  $^"
	@echo "The first request: $<"
	@echo "The target file:   $@"
	@echo "The full request:  $+"
	@echo "The target subfix: $*"
	@gcc $^ -o hello
	@echo "Compile Hello World!"


#hello_world.o: hello_world.c
#shared_a.o: shared_a.c

.PHONY: clean
clean: hello
	@rm -rf hello
	@rm -rf *.o
