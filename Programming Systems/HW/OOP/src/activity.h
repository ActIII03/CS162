//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Time Managment System

//Typcial Libraries
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstddef>
#include <cstdlib>

using namespace std;

#ifndef ACTIVITY
#define ACTIVITY

class activity
{
    public:
        //Default Constructor
        activity();
        //User-supplied
        activity(char * act_name, char * act_type, int act_len);
        //Copy constructor
        activity(const activity & to_copy);
        //Destructor
        ~activity();

        //Read-in function
        void read();


    protected:

        char * name_of_activity;
        char * category;
        int length;
};


class hobby: public activity
{
    public:
        hobby();
        // Create copy constructor
        ~hobby();

};

class work: public activity
{
    public:
        work();
        // Create copy constructor
        ~work();
};

class school: public activity
{
    public:
        school();
        school(char * assign_name);
        // Create copy constructor
        ~school();

        // Intake another derived object

    protected:
        char * assignment;
};
#endif 
