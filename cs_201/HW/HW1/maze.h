//Name: Armant Touche
//Class: CS 201
//Instructor: Raoul Rivas
//Description: Homework #1: Wall Follower

#include <stdio.h>
#include <stdlib.h>

//Open text file
int open_file(char* filename, FILE** read_file);
//Read-in text to 2D
int read_into_buffer(FILE** text_file, char* buffer);