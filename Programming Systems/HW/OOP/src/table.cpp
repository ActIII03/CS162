//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Time Managment System
#include "table.h"


day::day()
{
    day_of_week = NULL;
}

day::~day()
{
    if(day_of_week)
        delete day_of_week;
}

node::node()
{
    next = NULL;
}

node::~node()
{

}

table::table(int choice)
{
    size = 7;
    if(choice > 0)
        size = choice;

    array = new node * [size];
    
    for(int index = 0; index < size; ++index)
        *(array + index) = NULL;
}

table::~table()
{

}

int table::find_function(char * key)
{
    if(!key)
    {
        cout << "ERROR: Selection for the day to view was not made"
             << "\nExiting program" << endl;
        return 1;
    }

    int value = 0, length = strlen(key);

    for(int index = 0; index < length; ++index)
        value += key[index];

    return value % size;

}
