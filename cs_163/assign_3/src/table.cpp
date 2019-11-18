//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:
#include "table.h"


table::table(int size, int choice){

    if(choice)
       hash_table_size = choice;
    else
        hash_table_size = size;

    hash_table = new node * [hash_table_size];
    for(int index = 0; index < hash_table_size; ++index)
        *(hash_table + index) = NULL;

}


table::~table(){
    
    //Cycle through each indicies and delete from there

}


int table::insert(char * key_value, const CollegeHousing & to_add){

    int index = hash_function(key_value);

    node * temp = new node;

    //Insert via separate chaining
    temp -> next = hash_table[index];
    hash_table[index] = temp;

    return 0;
}

int table::retrieve(char * city_to_find, CollegeHousing & to_add) const
{
    
    return 0;

}

int table::retrieve_by_distance(int distance, CollegeHousing & to_delete)
{

    return 0;
}

int table::hash_function(char * key){

    int val = 0;

    for(int index = 0; index < hash_table_size; ++index)
        val += key[index];  //Fold each character and add the ACSII value

    return val % hash_table_size; //Return the corresponding key via modulo arithmetic

}


int table::display_all(void){


    return 0;

}
