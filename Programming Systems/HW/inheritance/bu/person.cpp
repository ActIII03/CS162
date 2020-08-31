//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Time Managment System
#include "person.h"


person::person()
{
    list_of_days = NULL;
}

person::~person()
{

}   

person::person(char * new_name)
{
    name = new char[strlen(new_name) + 1];
    strcpy(name, new_name);
}

void person::create_day_planner(int length)
{
    list_of_days = new planner(length);
    
}

void person::add_activity(activity & new_activity, hobby & fun, work & job, school & education, int type)
{
    list_of_days -> add_activity(new_activity, fun, job, education, type);
}

void person::display()
{
    list_of_days -> display();
}
