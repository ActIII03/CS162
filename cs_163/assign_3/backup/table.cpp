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

int table::delete_help(node * & current)
{

    if(!current)
        return 0;

    delete_help(current -> next);

    if(current)
        delete current;
 
    return 0;
}

table::~table()
{
    
    for(int index = 0; index < hash_table_size; ++index)
        delete_help(hash_table[index]);
    delete [] hash_table;

}

node::~node()
{
    if(col_house.name)
    {
        delete col_house.name;
        col_house.name = NULL;
    }
    if(col_house.location)
    {
        delete col_house.location;
        col_house.location = NULL;
    }
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
    traverse_list_for_name(name_to_find, current, to_add);

    return 0;

}

int table::delete_by_distance(int distance)
{
   
    node * current;

    for(int index = 0; index < hash_table_size; ++index)
    {
        current = hash_table[index];
        traverse_list_for_distance(distance, current);

    }

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
            cout << "\nName: " << current -> col_house.name;
            cout << "\nLocation: " << current -> col_house.location;
            cout << "\nSquare Footage: " << current -> col_house.sq_footage;
            cout << "\nNumber of Bedroom: " << current -> col_house.num_of_bedrm;
            cout << "\nDistance from PSU: " << current -> col_house.dist_from_psu << " miles" << endl;
        }
        current = current -> next;

    }

    return 0;
}

int table::traverse_list_for_distance(int distance, node * & current)
{
    //One item
    if(!current)
        return 0;

    if(current -> col_house.dist_from_psu > distance)
    {
        node * temp = current;
        current = current -> next; 
        delete temp;
        temp = NULL;
        return traverse_list_for_distance(distance, current);
    }

    return traverse_list_for_distance(distance, current -> next);

}

int table::traverse_list_for_name(char name[], node * & current, CollegeHousing & found)
{
    //Traverse possible chain
    while(current)
    {
        if(!(strcmp(name, current -> col_house.name)))
        {
            //Add a if statement to check prior existing data then delete then copy
            if(found.name)
            {
                delete found.name;
                delete found.location;
            }

            found.name = new char[strlen(current -> col_house.name) + 1];
            strcpy(found.name, current -> col_house.name);
            found.location = new char[strlen(current -> col_house.location) + 1];
            strcpy(found.location, current -> col_house.location);
            found.sq_footage = current -> col_house.sq_footage;
            found.num_of_bedrm = current -> col_house.num_of_bedrm;
            found.dist_from_psu = current -> col_house.dist_from_psu;
            return 0;
        }
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
