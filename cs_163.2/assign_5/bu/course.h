//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: Client Interface

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

#ifndef COURSE
#define COURSE

class Course
{
    public:

        //Constructor and Destructor
        Course();
        ~Course();

        //Get user's input
        int get_input(char * get_class);

        //Copy
        int copy_entry(Course & to_copy);

        //Compare
        int compare(char * is_match);

        //Delete
        int delete_class();

        //Display
        void display();

    private:

        char * class_name;
};
#endif

int menu();
