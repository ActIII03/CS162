//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

#ifndef ROUTES 
#define ROUTES 

struct dummy_struct
{
    char street[50];
    int length;
    char traffic_stat[50];
    char notes[50];
    char source[50];
};

class routes
{
    public:

        //Destructor and Constructor
        routes();
        ~routes();

        //Get user's input
        int create_route(const dummy_struct & add_route);  //<-- Add route arguments

        //Copy route
        int copy_route(routes & add_route);

        //Add Data mbr here
        char * street;
        int length;
        char * traffic_stat;
        char * notes;
        char * source;

};
#endif

int menu();
