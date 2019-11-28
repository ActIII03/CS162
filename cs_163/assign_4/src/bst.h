//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "college_house.h"

struct node
{
    CollegeHousing col_house;
    node * right;
    node * left;
};

class table
{
    public:

        table();   //Constructor
        ~table();  //Destructor

        //Add a new place by ASCII value of the first letter and if during insertion, if present node equals to-be-inserted node then evaluate next letter until they do not equal ASCII value
        int insert(CollegeHousing & to_add);  //Notes: Workon alphabetically insertion

        //Search by name (i.e., retrieve) and return to user
        int search(char * name, CollegeHousing & to_find);

        //Remove a single place by name
        int remove(char * name);

        //Display all location matches

        //Display in sorted order
        int display_sorted();

        //Get_height

        //Is_efficient (i.e., Balanced)
    
    private:

        node * root;

        //Recursive Functions
        int insert(node * & root, CollegeHousing & to_add);
        int search(node * root, char * name, CollegeHousing & found);
        int remove(char * name, node * & root);
        int display_sorted(node * root);
};
