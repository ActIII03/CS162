//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Time Managment System

#include "activity.h"

#ifndef TABLE
#define TABLE

class day
{
    public:
        day();
        ~day();

    protected:
        char * day_of_week;

};

class node: public day
{
    public:
        node();
        //node(const activity & new_activity);
        ~node();

        // Create node for day
        //int create();
        
    protected:

        //hobby fun_activity;
        //work nonfun_activity;
        //school education;

        activity * new_activity; 

        node * next;
        node * previous;

};

// Make array (1 - n)
class table
{
    public:
        table(int choice);
        ~table();

        // Insert/Add activity into table
        //int add_activity(const activity & new_activity, int day_of_week)
        // (1) Find location
        // (2) Check if DLL exists,
            // (2.1) None exisit, create node w/ node's public copy constructor
        // (3) Otherwise, traverse till end, use node's public copy constructor

        // Hash Function - Function does modulo arithmetic of the incoming day of week and depending on size of array where days are [1 - n].
        int find_function(char * key);

        // Check if empty

    protected:

        node ** array;
        int size;

};
#endif

