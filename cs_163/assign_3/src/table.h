//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "college_housing.h"


struct node{

    CollegeHousing col_house;
    node next;

};


class table{

    public:

        table(int size, int choice);
        ~table();
        int insert(char * key, const CollegeHousing & to_add);
        int retrieve(char * city_to_find, CollegeHousing & to_add) const;  //This a viable key and how to search by num of miles from PSU?
        int hash_function(char * city_to_find, CollegeHousing & found);
        int display_all(void);

    private:
    
        node ** hash_table;
        int hash_table_size;

};
