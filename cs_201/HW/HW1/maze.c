//Name: Armant Touche
//Class: CS 201
//Instructor: Raoul Rivas
//Description: Homework #1: Wall Follower

#include "maze.h"

int open_file(char* filename, FILE** read_file)
{
    if(!(*read_file = fopen(filename, "r")))
        return 0;
    return 1;
}


void read_into_buffer(FILE** text_file, int* x, int* y)
{
   
    char buffer[50];

    fscanf(*text_file, "%s\n", buffer);

    char* ptr;

    *y = strtol(buffer, &ptr, 10);
    *x = strtol(ptr +1, NULL, 10);

    return; 

}

char** allocate_2d(int mazesize_x, int mazesize_y)
{

    char** maze = (char**) malloc(sizeof(char*) * mazesize_x);

    for(int row = 0; row < mazesize_x; ++row)
        maze[row] = (char*) malloc(sizeof(char) * mazesize_y);

    return maze;

}

void create_maze(FILE** text_file, char** maze, int x, int y)
{

    for(int row = 0; row < x; ++row)
        fscanf(*text_file, "%s\n", maze[row]);

    return;
}

void display_maze(char** maze, int x, int y)
{

    printf("X:%d  Y:%d\n", x, y); 

    for(int row = 0; row < x; ++row)
    {
        for(int column = 0; column < y; ++column)
            printf("%c", maze[row][column]);

        printf("\n");
    }

}

/*  Wall Follower Algorithm
    1. If there is no Wall at the Right of the person, then turn right and walk one block
    2. Else, if there is no forward wall, then walk one block forward
    3. Else, if there is no left wall, then turn left and walk one block
    4. Else, turn 180 degree and walk one block forward
*/
