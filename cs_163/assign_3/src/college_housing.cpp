//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:
#include "college_housing.h"

CollegeHousing::CollegeHousing(){

    location = NULL;
    sq_footage = 0;
    num_of_bedrm = 0; 
    dist_from_psu = 0;

}

CollegeHousing::~CollegeHousing(){

    if(location)
    {
        delete location;
        location = NULL;
    }

}


int CollegeHousing::add_floorplan(char * new_location, int new_sq_ft, int new_num_bdrm, int new_PSU_dist)
{
    
    location = new char[strlen(new_location) + 1];
    strcpy(location, new_location);
    sq_footage = new_sq_ft;
    num_of_bedrm = new_num_bdrm;
    dist_from_psu = new_PSU_dist;

    return 0;

}


int CollegeHousing::retrieve(char * retrieve, CollegeHousing & found){


    return 0;
}


int CollegeHousing::display(void) const{


    return 0;

}
