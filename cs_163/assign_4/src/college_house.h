//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: Client interface for Floorplan repo

#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

#ifndef COLLEGE
#define COLLEGE

class CollegeHousing{

    public:

        CollegeHousing();  //Constructor
        ~CollegeHousing(); //Destructor

        //Add floorplan
        int add_floorplan(char * name, char * new_location, int new_sq_ft, int new_num_bdrm, int new_PSU_dist);

        //Copy info into current object
        int to_copy(CollegeHousing & to_copy);

        //Display a single name match
        int display_match(CollegeHousing & found) const;

        //Info being tracked 
        char * name;
        char * location;
        int sq_footage;
        int num_of_bedrm;
        int dist_from_psu;

};
#endif

//Menu interface for my client application
int menu_choice();
