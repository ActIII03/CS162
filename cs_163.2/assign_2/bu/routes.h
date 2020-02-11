//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>

using namespace std;

#ifndef ROUTES 
#define ROUTES 

struct a_route    
{
    char street[50];
    float length;
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
        int create_route(const a_route & add_route);  //<-- Add route arguments

        //Copy route
        int copy_route(routes & add_route);

        //Display route
        void display();

        //Add Data mbr here
        char * street;
        int length;
        char * traffic_stat;
        char * notes;
        char * source;

};
#endif

int menu();
