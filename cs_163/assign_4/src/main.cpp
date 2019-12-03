//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: This is the client application where this program acts a repo for floorplans

#include "bst.h"
#include "college_house.h"

int main(void){
    
    bool quit = false, efficient = false;
    char name[100], location[100];
    int sq_foot = 0, num_of_bdrm = 0, dist_from_PSU = 0, height = 0;

    //Construct table
    table BST;
    CollegeHousing floor_plan;

    //Read-in from file
    ifstream in_file;
    in_file.open("college_house.txt");
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
        BST.insert(floor_plan);

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

            BST.insert(floor_plan);

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
                BST.insert(floor_plan);
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
                if(!BST.search(name, floor_plan))
                {
                    floor_plan.display_match(floor_plan);
                        if(floor_plan.name)
                        {
                            delete floor_plan.name;
                            delete floor_plan.location;
                        }
                }
                else
                    cout << "\nNot Found!" << endl;
                break;

            case 3:
                //Remove by a name
                cout << "Please enter a name of a floorplan you want to get rid of: ";
                cin.get(name, 100, '\n');
                cin.ignore(100, '\n');
                BST.remove(name);
                break;

            case 4:
                //Display all location matches
                cout << "\nPlease enter the location for which floorplan(s) you want displayed: ";
                cin.get(location, 100, '\n');
                cin.ignore(100, '\n');
                BST.display_location(location);
                break;

            case 5:     
                //Display in Sorted order
                BST.display_sorted();
                break;

            case 6:
                //Get height
                height = BST.get_height();
                cout << "\nHeight of the BST is: " << height << endl;
                break;

            case 7:
                //Is efficient
                efficient = BST.is_efficient();
                if(efficient)
                    cout << "\nTree shape is balanced and efficient!" << endl;
                else 
                    cout << "\nTree isn't efficient!" << endl;
                break;

            case 8:
                //Remove enitres matching user's provided location
                cout << "\nPlease enter a location you want entries to be deleted by(e.g., Portland): ";
                cin.get(location, 100, '\n');
                cin.ignore(100, '\n');
                BST.remove_location(location);
                break;

            case 9:
                quit = true;
                break;
        }

    } while(!quit);

    return 0;

}

