.PHONY: clean
CFLAGS= -ansi -pedantic -O0 -Wall

all: prog 

prog: hello.o main.o
	gcc $(CFLAGS) hello.o main.o -o prog

main.o: main.c
	gcc -c main.c -o main.o

hello.o: hello.S
	as --64 hello.S -o hello.o

clean:
	rm -f *.o hw3 hw3a1
