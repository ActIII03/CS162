C_FLAGS = -Wall -O0 -std=c11 -g -Wpedantic -Wall -Werror=vla

C_FILES = $(shell find . -name '*.c') 

HW9: $(C_FILES)
	gcc $(C_FLAGS) -o HW9 $(C_FILES) -lm

clean:
	rm -f *.o a.out 

clean-all:
	rm -f *.o a.out HW9 

