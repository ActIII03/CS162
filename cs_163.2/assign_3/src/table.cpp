//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: 

#include "table.h"

table::table(int choice)
{
    size = 21;
    if(choice <= 0)
        size = choice;

    hash_table = new node * [size];
    for(int index = 0; index < size; ++index)
        *(hash_table + index) = NULL;
}

table::~table()
{

}

int table::insert(char * key_value, const Venue & to_add)
{
    return 0;
}

int table::retrieve(char * search_key, Venue & found)
{
    return 0;
}

int table::remove(char * search_key)
{
    return 0;
}

int table::display(char * search_key)
{
    return 0;
}

int table::hash_function(char * key)
{
    return 0;
}
