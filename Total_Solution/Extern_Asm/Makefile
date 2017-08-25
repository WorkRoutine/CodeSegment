all: sum

sum: sum.o main.o
	gcc -o $@ sum.o main.o

sum.o: sum.s
	gcc -o $@ -c $<

main.o: main.c
	gcc -o $@ -c $<

clean:
	rm -rf *.o
	rm -rf sum
