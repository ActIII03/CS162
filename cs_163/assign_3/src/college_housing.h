//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include <iostream>
#include <fstream>
#include <cstring>
#include "table.h"

using namespace std;


class CollegeHousing{

    public:

       CollegeHousing();
       ~CollegeHousing();
       int add_floorplan(const CollegeHousing & to_add);
       int retrieve(char * retrieve, CollegeHousing & found);
       int display(void) const;


    private:

        char * location;
        int sq_footage;
        int num_of_bedrm;
        int dist_from_psu;

};
