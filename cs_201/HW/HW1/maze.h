//Name: Armant Touche
//Class: CS 201
//Instructor: Raoul Rivas
//Description: Homework #1: Wall Follower

#include <stdio.h>
#include <stdlib.h>

//Open text file
int open_file(char* filename, FILE** read_file);

//Read-in text to 2D
void read_into_buffer(FILE** text_file, int* x, int* y);

//Dynamically Allocate 2D Array
char** allocate_2d(int mazesize_x, int mazesize_y);

//Create maze
void create_maze(FILE** text_file, char** maze, int x, int y);

//Display maze
void display_maze(char** maze, int x, int y);

//Solve maze
int right_wall_follow(char** maze, int start_x, int start_y, int mazesize_x, int mazesize_y, int exit_x, int exit_y);
