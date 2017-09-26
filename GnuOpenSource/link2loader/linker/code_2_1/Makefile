CC= gcc

PREPROCESS_FLAGS := -E 

preprocess: function.h function.c main.c
	@$(CC) function.c $(PREPROCESS_FLAGS) -o preprocess_function.i
	@$(CC) main.c $(PREPROCESS_FLAGS) -o preprocess_main.i
