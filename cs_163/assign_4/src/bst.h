//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: This is the ADT interface using BST as my data structure

#include "college_house.h"
#include <cmath>

//College housing node
struct node
{
    ~node();
    CollegeHousing col_house;
    node * right;
    node * left;
};

//BST data structure w/ node 
class table
{
    public:

        table();   //Constructor
        ~table();  //Destructor

        //Add a new place by ASCII value of the first letter and if during insertion, if present node equals to-be-inserted node then evaluate next letter until they do not equal ASCII value
        int insert(CollegeHousing & to_add);  //Notes: Workon alphabetically insertion

        //Search by name (i.e., retrieve) and return to user
        bool search(char * name, CollegeHousing & to_find);

        //Remove a single place by name
        int remove(char * name);   

        //Remove all location matches 
        int remove_location(char * location);  //Workon

        //Display all location matches
        int display_location(char * location);

        //Display in sorted order
        int display_sorted();

        //Get_height
        int get_height();

        //Check which subtree's height starting from root to furthest descendent is larger
        int is_max( int num_one, int num_two);

        //Is_efficient (i.e., Balanced and Complete)
        bool is_efficient();
    
    private:

        node * root;

        //Recursive Functions
        bool search_delete(char  * name, node * & root);
        void remove_all(node * & root);
        int remove_location(char * location, node * & root);
        int insert(node * & root, CollegeHousing & to_add);
        bool search(node * root, char * name, CollegeHousing & found);
        int remove_node(node * & root);
        int display_sorted(node * root);
        int display_location(char * location, node * root);
        int get_height(node * root);
        int is_efficient(node * root);

};
