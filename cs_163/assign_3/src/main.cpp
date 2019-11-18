//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "table.h"
#include "college_housing.h"

int main(void){
    
    int size = 17, choice = 0;
    cout << "Please enter a size of table you want(Optional): " << endl;
    cin >> choice;
    cin.ignore(100, '\n');

    char location[100];
    int sq_foot = 0, num_of_bdrm = 0, dist_from_PSU = 0, menu_choice = 0;

    //Construct table
    table prime_table(size, choice);
    CollegeHousing floor_plan;

    //Read-in from file
    ifstream in_file;
    in_file.open("college_housing.txt");
    char delimiter = ';';


    if(in_file)
    {
        in_file.get(location, 100, delimiter);
        in_file.ignore(100, delimiter);
        in_file >> sq_foot;
        in_file.ignore(100, delimiter);
        in_file >> num_of_bdrm;
        in_file.ignore(100, delimiter);
        in_file >> dist_from_PSU;
        in_file.ignore(100, delimiter);
        

        //After one instance, floor plan object
        floor_plan.add_floorplan(location, sq_foot, num_of_bdrm, dist_from_PSU);

        //Pass to table
        prime_table.insert(location, floor_plan);

        //Prime the pump
        in_file.get(location, 100, delimiter);
        in_file.ignore(100, delimiter);

        //Read in until EOF flag is set
        while(in_file && !in_file.eof())
        {

            in_file >> sq_foot;
            in_file.ignore(100, delimiter);
            in_file >> num_of_bdrm;
            in_file.ignore(100, delimiter);
            in_file >> dist_from_PSU;
            in_file.ignore(100, delimiter);

            floor_plan.add_floorplan(location, sq_foot, num_of_bdrm, dist_from_PSU);

            prime_table.insert(location, floor_plan);

            //Prime the pump
            in_file.get(location, 100, delimiter);
            in_file.ignore(100, delimiter);

        }
        
    }
    return 0;
    
    switch(menu_choice)
    {
        case 1:
            //Add floorplan
            break;
        case 2:
            //Display all by location match
            break;
        case 3:
            //Delete by miles less than or equal to user's inputted distance
            break;
        case 4:
            //retrieve by location keyword match
            break;
            

    }
