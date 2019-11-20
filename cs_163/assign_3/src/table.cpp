//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:
#include "table.h"


table::table(int size, int choice){

    if(!choice)
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


//Why isn't data inserted into the new node?
int table::insert(char * key_value, const CollegeHousing & to_add){

    int index = hash_function(key_value);

    node * temp = new node;

    if(temp -> col_house.to_copy(to_add))  //Is this viable?
    {
        delete temp;
        temp = NULL;
        return 0;
    }

    //Insert via separate chaining
    temp -> next = hash_table[index];
    hash_table[index] = temp;

    return 0;
}

int table::retrieve(char * name_to_find, CollegeHousing & to_add)
{
   
    int index = hash_function(name_to_find);
    char possible_name[100];

    node * current = hash_table[index];

    //Search index for more than one link
    if(!current)
        return 1;
    
    while(current)
    {

        current -> col_house.get_name(possible_name);

        if( strcmp(possible_name, name_to_find) )  
            to_add.to_copy(current -> col_house);  
        
        else
            current = current -> next;
    }

    return 0;

}

int table::delete_by_distance(int distance, CollegeHousing & to_delete)
{
    /*
    int hash_index = 0
    
    while(hash_index < hash_table_size)
    {

        node * current = hash_table[index];

        while(current)
        {

    */

    return 0;
}

int table::retrieve_by_city(int location, CollegeHousing & to_display, int & indices, bool & end_of_index)
{

    char city[100];

    //How to do this?
    //For each of the indices
    for(int index = 0; index < hash_table_size; ++index)
    {

            //Search each Linked List and compare node pointer to location 
            //While not reachng end
            for(node * current = hash_table[index]; current; current = current -> next)
            {
                current -> col_house.get_name(city);

                //If found, copy over to
                if(strcmp(possible_name, name_to_find) )  
                    to_add.to_copy(current -> col_house);  
            } 
    }

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
