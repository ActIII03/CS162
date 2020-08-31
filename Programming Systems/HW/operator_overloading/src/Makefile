CPP_FLAGS = -g -Werror=vla -ansi

CPP_FILES = $(shell find . -name '*.cpp' ! -name 'unit_test.cpp')

UNIT_TEST = $(shell find . -name '*.cpp' ! -name 'main.cpp')

all: 
	g++ $(CPP_FLAGS) $(CPP_FILES) -o fishbowl

test: 
	g++ $(TEST_CPP_FLAGS) $(UNIT_TEST) -o test 
	./test
	rm test 

vtest: 
	g++ $(TEST_CPP_FLAGS) $(UNIT_TEST) -o test 
	valgrind --leak-check=full ./test
	rm test 

prog: 
	g++ $(CPP_FLAGS) $(UNIT_TEST) -o test 

clean:
	rm fishbowl test

