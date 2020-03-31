//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: 

#include "venue.h"

struct node
{
    node();
    Venue venue_entry;
    node * right;
    node * left;
};

class table
{
    public:

        // Constructor and Destructor
        table();
        ~table();

        // (1) Insert into BST
        int insert(Venue & to_add);

        // (2) Search for a particular meal(s)
        int search_meal(char * to_find, Venue & found);

        // (3) Remove by meal
        int remove(char * to_remove);

        // (4) Display
        int display(char * search, a_venue matches[], int choice);

        // (5) Get height of BST
        int get_height();

        // (6) Is tree balanced  <--- check R & L sbutree's difference is not greater than one
        int is_efficient();
       
        // (7) Is max
        int is_max(int left_height, int right_height);
        
    private:

        // Recursive functions

        // (1)
        int insert(node * & root, Venue & to_add);

        // (2)
        int search_meal(node * root, char * search, Venue & found);

        // (3)
        int remove(node * & root, char * to_remove);

        // (4) Retrieve meal(s)
        int retrieve_meal(node * root, char * search, a_venue matches[], int & MAX);

        // (4.1) Display all matching meals
        int display_matched_meals(node * root, char * match);

        // (4.2)
        int display_sorted(node * root);

        // (6)
        int get_height(node * root);

        // Destructor Helper
        void destory(node * & root);

        node * root;
        int MAX;
};
