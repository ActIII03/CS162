C_FLAGS = -Wall -O0 -std=c11 -g -Wpedantic -Wall -Werror=vla

C_FILES = $(shell find . -name '*.c')

maze_runner: $(C_FILES)
	gcc $(C_FLAGS) -o maze_runner $(C_FILES)

clean:
	rm -f *.o a.out 

clean-all:
	rm -f *.o a.out maze_runner
