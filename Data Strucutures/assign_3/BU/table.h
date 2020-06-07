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
        int retrieve(char * search_key, Venue & found, int & choice);
        
        // Remove from table
        int remove(char * search_key, int option);

        // Remove a venue 
        int remove_venue(char * search_key);

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

        // Retrieve venue
        int remove_venue(node * & head, char * search_key); 

        // Retrieve a venue 
        int retrieve_meal(node * head, char * search_key, Venue & found, int & number_of_venues);

        // Display
        int display(node * head, char * search_key);

        // LLL destructor
        void destory_LLL(node * & head);
    
        node ** hash_table;
        int size;
};
