//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

//What are these pre-processors for?
#ifndef COLLEGE
#define COLLEGE

class CollegeHousing{

    public:

       CollegeHousing();
       ~CollegeHousing();
       int add_floorplan(char * new_location, int new_sq_ft, int new_num_bdrm, int new_PSU_dist);
       int retrieve(char * retrieve, CollegeHousing & found);
       int display(void) const;


    private:

        char * location;
        int sq_footage;
        int num_of_bedrm;
        int dist_from_psu;

};
#endif
