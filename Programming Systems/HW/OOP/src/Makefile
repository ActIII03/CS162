CPP_FLAGS = -g -Werror=vla -Wall -ansi

CPP_FILES = $(shell find . -name '*.cpp')

UNIT-TEST = $(shell find . -name '*.cpp' ! -name 'main.cpp')

all: 
	g++ $(CPP_FLAGS) $(CPP_FILES) -o time_mgmt

unit-test:
	g++ $(CPP_FLAGS) $(UNIT-TEST) -o test-tms

clean:
	rm time_mgmt
