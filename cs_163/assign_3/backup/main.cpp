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
    bool quit = false;

    char name[100], location[100];
    int sq_foot = 0, num_of_bdrm = 0, dist_from_PSU = 0;

    //Construct table
    table prime_table(size, choice);
    CollegeHousing floor_plan;

    //Read-in from file
    ifstream in_file;
    in_file.open("college_housing.txt");
    char delimiter = ';';

    //Delete before submission?
    if(in_file)
    {
        in_file.get(name, 100, delimiter);
        in_file.ignore(100, delimiter);
        in_file.get(location, 100, delimiter);
        in_file.ignore(100, delimiter);
        in_file >> sq_foot;
        in_file.ignore(100, delimiter);
        in_file >> num_of_bdrm;
        in_file.ignore(100, delimiter);
        in_file >> dist_from_PSU;
        in_file.ignore(100, delimiter);
        

        //After one instance, floor plan object
        floor_plan.add_floorplan(name, location, sq_foot, num_of_bdrm, dist_from_PSU);

        //Pass to table
        prime_table.insert(name, floor_plan);

        if(floor_plan.name)
        {
            delete floor_plan.name;
            delete floor_plan.location;
        }

        //Prime the pump
        in_file.get(name, 100, delimiter);
        in_file.ignore(100, delimiter);

        //Read in until EOF flag is set
        while(in_file && !in_file.eof())
        {

            in_file.get(location, 100, delimiter);
            in_file.ignore(100, delimiter);
            in_file >> sq_foot;
            in_file.ignore(100, delimiter);
            in_file >> num_of_bdrm;
            in_file.ignore(100, delimiter);
            in_file >> dist_from_PSU;
            in_file.ignore(100, delimiter);

            floor_plan.add_floorplan(name, location, sq_foot, num_of_bdrm, dist_from_PSU);

            prime_table.insert(name, floor_plan);

            if(floor_plan.name)
            {
                delete floor_plan.name;
                delete floor_plan.location;
            }

            //Prime the pump
            in_file.get(name, 100, delimiter);
            in_file.ignore(100, delimiter);

        }

        in_file.close();
        in_file.clear();
        
    }
    
    do
    {
        switch(menu_choice())
        {
            case 1:
                //Add floorplan
                cout <<  "Please enter a Name: ";
                cin.get(name, 100, '\n');
                cin.ignore(100, '\n');
                cout << "Please enter a Location(City): ";
                cin.get(location, 100, '\n');
                cin.ignore(100, '\n');
                cout << "Please enter square footage: ";
                cin >> sq_foot;
                cin.ignore(100, '\n');
                cout << "Please enter Number of bedrooms: ";
                cin >> num_of_bdrm;
                cin.ignore(100, '\n');
                cout << "Please enter Distance from PSU: ";
                cin >> dist_from_PSU;
                cin.ignore(100, '\n');
                floor_plan.add_floorplan(name, location, sq_foot, num_of_bdrm, dist_from_PSU);
                prime_table.insert(name, floor_plan);
                if(floor_plan.name)
                {
                    delete floor_plan.name;
                    delete floor_plan.location;
                }

                break;

            case 2:      
                //Display a single name match
                cout << "Which floorplan do you want to lookup?(Name): ";
                cin.get(name, 100, '\n');
                cin.ignore(100, '\n');
                prime_table.retrieve(name, floor_plan);
                floor_plan.display_match(floor_plan);
                break;

            case 3:
                cout << "Please enter a desired distance from Campus you want to store and anything floorplans greater than your input will be deleted: ";
                cin >> dist_from_PSU;
                cin.ignore(100, '\n');
                prime_table.delete_by_distance(dist_from_PSU);
                break;

            case 4:     
                //Display all location matches
                cout << "Please enter a city(i.e., Portland): ";
                cin.get(location, 100, '\n');
                cin.ignore(100, '\n');
                prime_table.display_by_city(location);
                break;
            case 5:
                quit = true;
                break;
        }

    } while(!quit);

    return 0;

}

