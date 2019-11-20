//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include <cstring>
#include "college_housing.h"

using namespace std;

struct node{

    CollegeHousing col_house;
    node * next;

};


class table{

    public:

        table(int size, int choice);
        ~table();
        int insert(char * key_value, const CollegeHousing & to_add);
        int retrieve(char * name_to_find, CollegeHousing & to_add); 
        int delete_by_distance(int distance, CollegeHousing & to_delete);
        int retrieve_by_city(int location, CollegeHousing & to_display);
        int hash_function(char * key);
        int display_all(void);
        //traversal helper function here

    private:
    
        node ** hash_table;
        int hash_table_size;

};
