//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: 

#include "venue.h"

struct node
{
    Venue venue_entry;
    node * next;
};

class table
{
    public:

        //Constructor and Destructor
        table(int choice);
        ~table();

        // Insert into hash table
        int insert(char * key_value, const Venue & to_add); 

        // Retrieve index where entry is at in table
        int retrieve(char * search_key, Venue & found);
        
        // Remove from table
        int remove(char * search_key);

        //Display by meal
        int display(char * search_key);

        // Hash function
        int hash_function(char * key);

    private:

        node ** hash_table;
        int size;
};
