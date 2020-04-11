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
    /* Read-in text file into 2D character pointer array
       Lines from txt file(X,Y):
       1. <number_of_rows_in_maze>,<number_of_columns_in_maze>
       2. <row_entry_point>, <column_entry_point>
       3. <row_exit_point>, <column_exit_point>
       */

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

    printf("Before solving:\n");

    for(int row = 0; row < x; ++row)
    {
        for(int column = 0; column < y; ++column)
            printf("%c", maze[row][column]);

        printf("\n");
    }

}

int right_wall_follow(char** maze, int start_x, int start_y, int mazesize_x, int mazesize_y, int exit_row, int exit_column)
{

    /*  
        Wall Follower Algorithm
        1. If there is no Wall at the right of the person, then turn right and walk one block
        2. Else, if there is no forward wall, then walk one block forward
        3. Else, if there is no left wall, then turn left and walk one block
        4. Else, turn 180 degree and walk one block forward
    */

    int walk_row = start_x;
    int walk_column = start_y;

    maze[walk_row][walk_column] = 'W';

    int moves = 1;
    int direction = 2;

    while(walk_column != exit_column || walk_row != exit_row)
    {
        //Facing North
        if(direction == 0)
        {

        }
        //Facing East
        else if(direction == 1)
        {

        }
        //Facing South
        else if(direction == 2)
        {
            //Go right
            if(maze[walk_row][walk_column - 1] != 'X')
            {
                //Update maze[][] --> W
                maze[walk_row][walk_column - 1] = 'W';
                //Move right by updating walk(y, x - 1)
                --walk_column;
            }
            //Check for forward wall
            else if(maze[walk_row + 1][walk_column] == '0' || maze[walk_row + 1][walk_column] == 'W')
            {
                //Update maze[][] --> W
                maze[walk_row + 1][walk_column] = 'W';
                //Move forward by updating walk(y + 1, x)
                ++walk_row;
            }
            //Check left wall
            else if(maze[walk_row][walk_column + 1] == '0')
            {
                //Update maze[][] --> W
                maze[walk_row][walk_column + 1] = 'W';
                //Move forward by updating walk(y, x + 1)
                ++walk_column;
            }
            //Facing West
            else
                //Move backwards by updating walk(y - 1, x)
                --walk_row;
        }
        else
        {

        }

        printf("Move: %d", ++moves);

    }

    return 0;
}
