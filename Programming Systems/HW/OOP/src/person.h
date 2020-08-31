//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Time Managment System

#include "table.h"

bool again();

const int MAX = 100;

#ifndef PERSON
#define PERSON

class person
{
    public:
        person();
        ~person();

        //Create table
        void create_day_planner(int length); // list_of_days = new table(length);

        //Add activity to table
        //int add_activity(const activity & new_activity){
        //  list_of_days.add_activity(new_activity, day_of_week); <


    protected:

        table * list_of_days;
};
#endif

