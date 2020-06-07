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

    for(int index = 0; index < size; ++index)
    {
        if(hash_table[index])
        {
            destory_LLL(hash_table[index]);  
            hash_table[index] = NULL;
        }
    }

    delete [] hash_table;
    hash_table = NULL;

}

void table::destory_LLL(node * & head)
{
    if(!head)
    {
        head = NULL;
        return;
    }

    node * temp = head -> next;
    delete head;
    head = temp;
    destory_LLL(head);
    return;
}

// Work on tomorrow
int table::insert(Venue & to_add)
{
    int index = hash_function(to_add.meal);

    if(index < 0)
        return -99;

    node * new_node = new node;

    if(!new_node -> venue_entry.copy_venue(to_add))
    {
        delete new_node;
        return -99;
    }

    //Check to see if address is open and if occupied, apply chaining
    if(hash_table[index])
    {
        new_node -> next = hash_table[index];
        hash_table[index] = new_node;

    }
    // If no object at an index, attach to index
    else
    {
        hash_table[index] = new_node;  // Imagine hash_table[index] as head
        new_node -> next = NULL;
    }

    return 0;
}

int table::retrieve(char * search_key, Venue & found, int & choice)
{
    if(!is_empty())
        return -99;

    int result = 0, temp = choice;

    for(int index = 0;result == 0 && index < size; ++index)
        result = retrieve_meal(hash_table[index], search_key, found, choice);

    choice = temp;

    return result;
}


int table::retrieve_meal(node * head, char * search_key, Venue & found, int & number_of_venues)
{
    int result = 0;

    if(!head)
        return result;
    
    if(strcmp(head -> venue_entry.meal, search_key) == 0 && number_of_venues == 0)
    {
        found.copy_venue(head -> venue_entry);
        return 1;
    }
    else if(strcmp(head -> venue_entry.meal, search_key) == 0 && number_of_venues != 0)
        --number_of_venues;

    result = retrieve_meal(head -> next, search_key, found, number_of_venues);
    return result;

}

int table::remove(char * search_key, int choice)
{
    if(!search_key)
        return -99;

    if(!is_empty())
        return -99;

    int result = 0;

    if(choice == 1)
    {
        // Pass meal as search key
        int index = hash_function(search_key);
        result = remove_meal(hash_table[index], search_key);
    }
    else
        // Pass venue(cart) name as search key
        result = remove_venue(search_key);

    return result;
}

int table::remove_meal(node * & head, char * search_key)
{
    // No items
    if(!head)
        return -99;
    
    // One item
    if(!head -> next)
    {
        delete head;
        head = NULL;
        return 0;
    }

    // Compare for match and remove if true
    if(strcmp(head -> venue_entry.meal, search_key) == 0)
    {
        node * temp = head;
        head = head -> next;
        delete temp;
        return 0;
    }
    return remove_meal(head -> next, search_key);
}

int table::remove_venue(char * search_key)
{

    int result = 0;

    for(int index = 0; index < size; ++index)
        result += remove_venue(hash_table[index], search_key);

    return result;
}

int table::remove_venue(node * & head, char * search_key)
{
    int count = 0;

    if(!head)

        return 0;

    if(strcmp(head -> venue_entry.name, search_key) == 0)
    {
        ++count;
        node * temp = head -> next;
        delete head;
        head = temp;
        count += remove_venue(head, search_key);
    }
    else
        count += remove_venue(head -> next, search_key);

    return count;
}

int table::display(char * search_key)
{

    if(!is_empty())
        return -99;

    int result = 0;

    for(int index = 0; index < size; ++index)
        display(hash_table[index], search_key);  //Add count

    return result;
}

int table::display(node * head, char * search_key)
{

    int result = 0;

    if(!head)
        return result + 1;

    if(strcmp(head -> venue_entry.meal, search_key) == 0)
    {
        cout << "\nMeal name: " << head -> venue_entry.meal 
             << "\nVenue Name: " << head -> venue_entry.name
             << "\nPrice: " << head -> venue_entry.price
             << "\nRating: " << head -> venue_entry.rating
             << "\nVenue type: " << head -> venue_entry.category << endl;
    }

    result += display(head -> next, search_key);

    return result;
}

int table::hash_function(char * key)
{

    if(!key)
        return -99;

    int value = 0, length = strlen(key);

    for(int index = 0; index < length; ++index)
        value += key[index];

    return value % size;
}

int table::is_empty()
{
    bool flag = false; 
    
    for(int index = 0;index < size; ++index)
    {
        if( *(hash_table + index) )
            flag = true;
    }

    return flag;
}
