//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include <cstring>
#include "college_housing.h"

using namespace std;

struct node{

    ~node();
    CollegeHousing col_house;
    node * next;

};


class table{

    public:

        table(int size, int choice);
        ~table();
        int insert(char * key_value, CollegeHousing & to_add);
        int retrieve(char name_to_find[], CollegeHousing & to_add); 
        int delete_by_distance(int distance);
        int display_by_city(char location[]);
        int hash_function(char * key);

    private:
    
        int delete_help(node * & current);
        int traverse_list_for_location(char location[], node * current);
        int traverse_list_for_distance(int distance, node * & current);
        int traverse_list_for_name(char name[], node * & current, CollegeHousing & found);
        node ** hash_table;
        int hash_table_size;

};
