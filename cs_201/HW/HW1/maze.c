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


int read_into_buffer(FILE** text_file, char* buffer)
{
    int result;

    //Set up buffer
    fseek(*text_file, 0, SEEK_END); //Orient read-in position which is at the beginning in our case
    long length = ftell(*text_file); //Returns file postion indicator for file stream
    buffer = malloc(length);

    if(buffer)
        result = fread(buffer, 1, length, *text_file);

    if(result)
        return 1;
    else
        fclose(*text_file);

    for(int i = 0; i < 6; ++i)
        printf("Stuff: %d \n", buffer[i]);

    return 1;

}
