C_FLAGS = -Wall -O0 -std=c11 -g -Wpedantic -Wall -Werror=vla

C_FILES = $(shell find . -name '*.c')

midterm: $(C_FILES)
	gcc $(C_FLAGS) -o midterm $(C_FILES)

clean:
	rm -f *.o a.out midterm
