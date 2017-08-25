all:
	@gcc mylib.c -c -o mylib.o
	@ar rcs libmylib.a mylib.o
	@gcc main.c libmylib.a -o a
	@echo "Compile finish"
