//Name: Armant Touche
//Class: CS 201
//Instructor: Raoul Rivas
//Description: Homework #1: Wall Follower

#include "maze.h"

/* Wall Follower Algorithm
    1. If there is no Wall at the Right of the person, then turn right and walk one block
    2. Else, if there is no forward wall, then walk one block forward
    3. Else, if there is no left wall, then turn left and walk one block
    4. Else, turn 180 degree and walk one block forward
*/

//Logic driver
int main(int argc, char * argv[])
{

    /* Read-in text file into 2D character pointer array
           Lines from txt file(X,Y):
           1. <number_of_rows_in_maze>,<number_of_columns_in_maze>
           2. <row_entry_point>, <column_entry_point>
           3. <row_exit_point>, <column_exit_point>
    */


    if(argc != 2) return 1; //check for commandline arguments
    FILE* text_file;
    //char** maze;  //Soon-to-be 2d of the maze
    char* buffer;
    //int mazesize_x, mazesize_y, start_x, start_y, exit_x, exit_y;

    //Check and set pointer to text file for read-in
    if(!open_file(argv[1], &text_file))
    {
        printf("\nOPEN_FILE: ERROR opening file. \n");
        return 1;
    }
    else
        printf("\nSuccesful file open!\n");

    //Read-in from text into: entrance, exit, maze
    
    int result = read_into_buffer(&text_file, &buffer); 

    //Check for result of 
    if(!result)
        printf("\n Succesful read-in!\n");
    else
    {
        printf("\n Failed to read-in!\n");
        return 1;
    }


    //Dynamically Allocate 2d array and read-in layout from file


    fclose(text_file);

    return 0;
}
