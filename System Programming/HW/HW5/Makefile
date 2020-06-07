.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall

all: hw5 hw5a1

hw5: hw5.o fib.o
	gcc -g -o hw5 $(CFLAGS) hw5.o fib.o

hw5a1: hw5.o fiba.o
	gcc -g -o hw5a1 $(CFLAGS) hw5.o fiba.o

hw5.o: hw5.c
	gcc -c -g -o hw5.o $(CFLAGS) hw5.c

fib.o: fib.c
	gcc -c -g -o fib.o $(CFLAGS) fib.c

fiba.o: fiba.S
	as --64 -o fiba.o fiba.S

clean:
	rm -f *.o hw5 hw5a1
