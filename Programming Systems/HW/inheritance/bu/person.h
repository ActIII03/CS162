//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Time Managment System

#include "planner.h"

#ifndef PERSON
#define PERSON

class person
{
    public:
        person();
        person(char * new_name);
        ~person();

        //Create planner
        void create_day_planner(int length); // list_of_days = new planner(length);
        //Add activity to planner
        void add_activity(activity & new_activity, hobby & fun, work & job, school & education, int type);
        //Display planner
        void display();

    protected:
        
        char * name;
        planner * list_of_days;
};
#endif

