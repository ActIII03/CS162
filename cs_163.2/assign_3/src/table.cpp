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

// Work on tomorrow
int table::insert(const Venue & to_add)
{
    int index = hash_function(to_add.meal);

    if(index < 0)
        return -99;

    node * new_node = new node;

    if(!new_node -> venue_entry.copy_entry(to_add))
    {
        delete new_node;
        return -99;
    }

    //Check to see if address is open and if occupied, apply chaining
    if(hash_table[index])
    {

    }
    else
    {
        hash_table[index] = new_node;
        new_node -> next = NULL;
    }


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

    if(!key)
        return -99;

    int value = 0;

    for(int index = 0; index < size; ++index)
        value += key[index];

    return value % size;
}
