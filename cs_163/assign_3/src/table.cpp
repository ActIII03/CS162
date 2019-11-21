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
int table::insert(char * key_value, CollegeHousing & to_add){

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

int table::retrieve(char name_to_find[], CollegeHousing & to_add)
{
   
    int index = hash_function(name_to_find);
    node * current = hash_table[index];

    //Empty Index
    if(!current)
        return 1;
    traverse_list_for_location(name_to_find, current);

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

int table::display_by_city(char location[])
{
    
    node * current;

    for(int index = 0; index < hash_table_size; ++index)
    {
        current = hash_table[index]; 
        traverse_list_for_location(location, current);
    }

    return 0;
}

int table::traverse_list_for_location(char location[], node * current)
{

    //Traverse Possible chain
    while(current)
    {
        
        if(!(strcmp(current -> col_house.location, location)))
        {
            cout << "Name: " << current -> col_house.name;
            cout << "\nLocation: " << current -> col_house.location;
            cout << "\nSquare Footage: " << current -> col_house.sq_footage;
            cout << "\nNumber of Bedroom: " << current -> col_house.num_of_bedrm;
            cout << "\nDistance from PSU: " << current -> col_house.dist_from_psu << " miles" << endl;
        }
        current = current -> next;

    }

    return 0;
}

int table::traverse_list_for_name(char name[], node * current, CollegeHousing & found)
{
    //Traverse possible chain
    while(current)
    {
        if(!(strcmp(name, current -> col_house.name)))
        {
            strcpy(found.name, current -> col_house.name);
            strcpy(found.location, current -> col_house.location);
            found.sq_footage = current -> col_house.sq_footage;
            found.num_of_bedrm = current -> col_house.num_of_bedrm;
            found.dist_from_psu = current -> col_house.dist_from_psu;
        }
        else
            current = current -> next;
    }
    
    return 0;
}

int table::hash_function(char * key){

    int val = 0;

    for(int index = 0; index < hash_table_size; ++index)
        val += key[index];  //Fold each character and add the ACSII value

    return val % hash_table_size; //Return the corresponding key via modulo arithmetic

}
