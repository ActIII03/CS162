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
        int insert(Venue & to_add); 

        // Retrieve index where entry is at in table
        int retrieve(char * search_key, Venue & found);
        
        // Remove from table
        int remove(char * search_key, int option);

        //Display by meal
        int display(char * search_key);

        // Hash function
        int hash_function(char * key);

        // Check if table is empty
        int is_empty();

    private:

        // Display meal matches
        int display_meal_list(node * head);

        // Remove meal
        int remove_meal(node * & head, char * search_key);

        // Remove a venue 
        int remove_venue(char * search_key);
    
        node ** hash_table;
        int size;
};
