//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:
#include "college_house.h"

CollegeHousing::CollegeHousing(){

    location = NULL;
    sq_footage = 0;
    num_of_bedrm = 0; 
    dist_from_psu = 0;

}

CollegeHousing::~CollegeHousing(){

    if(name)
    {
        delete name;
        name = NULL;
    }
    if(location)
    {
        delete location;
        location = NULL;
    }

}


int CollegeHousing::add_floorplan(char * new_name, char * new_location, int new_sq_ft, int new_num_bdrm, int new_PSU_dist)
{
    
    name = new char[strlen(new_name) + 1];
    strcpy(name, new_name);
    location = new char[strlen(new_location) + 1];
    strcpy(location, new_location);
    sq_footage = new_sq_ft;
    num_of_bedrm = new_num_bdrm;
    dist_from_psu = new_PSU_dist;

    return 0;

}


int CollegeHousing::to_copy(CollegeHousing & to_copy)
{
    
    name = new char[strlen(to_copy.name) + 1];
    strcpy(name, to_copy.name);
    location = new char[strlen(to_copy.location) + 1];
    strcpy(location, to_copy.location);
    sq_footage = to_copy.sq_footage;
    num_of_bedrm = to_copy.num_of_bedrm;
    dist_from_psu = to_copy.dist_from_psu;

    return 0;
}

int CollegeHousing::display_match(CollegeHousing & found) const{

    cout << "\nName: " << found.name << "\nLocation: " << found.location
         << "\nSquare footage: " << found.sq_footage << "\nNumber of bedrooms: " << found.num_of_bedrm
         << "\nDistance from PSU(miles): " << found.dist_from_psu << endl;

    return 0;
}

int menu_choice()
{
    int menu_choice = 8;
    cout << "\nHere are the choices:\n(1) Add floorplan\n(2) Display by name\n(3) Remove a singular floorplan by name \n(4) Display by location\n(5) Display All in Alphabetical Order"
         << "\n(6) Get Height of BST\n(7) Is BST efficient\n(8) Quit Program" << endl;
    cout << "\nChoice(1-8): ";
    cin >> menu_choice;
    cin.ignore(100, '\n');

    return menu_choice;
}

bool again()
{
    char choice = 'Y';

    cout << "Would you like to continue using this program?(Y/N): ";
    cin >> choice;
    cin.ignore(100, '\n');

    if(toupper(choice) == 'Y' || choice == 'y')
        return true;
    
    return false;
}

