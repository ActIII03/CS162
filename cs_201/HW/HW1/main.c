//Name: Armant Touche
//Class: CS 201
//Instructor: Raoul Rivas
//Description: Homework #1: Wall Follower

#include "maze.h"

//Logic driver
int main(int argc, char * argv[])
{

    if(argc != 2) return 1; //check for commandline arguments
    FILE* text_file;
    char** maze;  //Soon-to-be 2d of the maze
    int mazesize_x, mazesize_y, start_x, start_y, exit_x, exit_y = 0;

    //Check and set pointer to text file for read-in
    if(!open_file(argv[1], &text_file))
    {
        printf("\nOPEN_FILE: ERROR opening file. \n");
        return 1;
    }
    else
        printf("Successful file open!\n\n");

    //Read-in from text into: entrance, exit, maze
    read_into_buffer(&text_file, &mazesize_x, &mazesize_y); 
    read_into_buffer(&text_file, &start_x, &start_y); 
    read_into_buffer(&text_file, &exit_x, &exit_y); 

    //Dynamically Allocate 2d array and read-in layout from file
    maze = allocate_2d(mazesize_x, mazesize_y);

    //Read-in maze layout
    create_maze(&text_file, maze, mazesize_x, mazesize_y);

    //Display maze before solving
    display_maze(maze, mazesize_x, mazesize_y);

    //Solve maze
    right_wall_follow(maze, start_x, start_y, mazesize_x, mazesize_y, exit_x, exit_y);
    
    //Display maze before solving
    printf("\nAfter solving:\n");
    display_maze(maze, mazesize_x, mazesize_y);

    //Close file obj
    fclose(text_file);

    return 0;
}
