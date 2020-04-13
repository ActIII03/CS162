Name: Armant Touche
Class: CS 201
Instructor: Raoul Rivas
Description: Maze Solver Program

Instructions:

To compile program:

$ make

To run program:

$ ./maze-runner <maze>.txt

Notes:

This program demonstrates allocating 2d array via pointers with the malloc() function and also demonstrates parsing command line arguments which supply the name of the text file containing the maze specification. Last thing, when compiling w/ the -Werror flag, one error is produced due to referencing a "possible" undefined variable but I do define and initlize the variable but further researched suggested that the ambigous relatioship of precedence and gcc. I didn't really think the error was neccessary because I am comfortable with precedence of the pre-increment and modulo operator.
