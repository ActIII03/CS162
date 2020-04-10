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

int right_wall_follow(char** maze, int start_x, int start_y, int mazesize_x, int mazesize_y, int exit_x, int exit_y)
{

    /*  Wall Follower Algorithm
        1. If there is no Wall at the Right of the person, then turn right and walk one block
        2. Else, if there is no forward wall, then walk one block forward
        3. Else, if there is no left wall, then turn left and walk one block
        4. Else, turn 180 degree and walk one block forward
    */

    int walk_x = start_x;
    int walk_y = start_y;


    maze[walk_y][walk_x] = 0;

    while(walk_y != exit_y && walk_x != exit_x)
    {
        //Check for right wall
        else if(maze[walk_y][walk_x - 1] != "X")
        {
            //Update maze[][] --> W
            maze[walk_y][walk_x - 1] = "W";
            //Move right by updating walk(y, x - 1)
            --walk_x;

        }
        //Check for forward wall
        else if(maze[walk_y + 1][walk_x] != "0" || maze[walk_y + 1][walk_x] == "W")
        {
            //Update maze[][] --> W
            if(maze[walk_y + 1][walk_x] != "0"
                maze[walk_y + 1
            //Move forward by updating walk(y + 1, x)


        }
        //Check left wall
        else if(maze[walk_y][walk_x + 1] == "0")
        {
            //Update maze[][] --> W
            //Move forward by updating walk(y, x + 1)

        }
        else
        {
            //Move backwards by updating walk(y - 1, x)

        }


    }

    printf("\nAfter solving:\n");

    return 0;
}
