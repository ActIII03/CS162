//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: 

#include "venue.h"
#include "table.h"

int main(void)
{
    int choice = 0;

    cout << "What will be the size of the table?: " << endl;
    cin >> choice;
    cin.ignore(100, '\n');

    Venue new_venue;  // Client 
    table my_table(choice); // ADT hash table
    a_venue in_venue;  // struct to hold stuff

    bool quit = false;


    // Read-in from file
    ifstream in_file;
    in_file.open("venues.txt");
    char delimiter = ';';

    if(in_file)
    {
        // Read-in first entry
        in_file.get( in_venue.meal, 30, delimiter);
        in_file.ignore(100, delimiter);
        in_file.get( in_venue.name, 30, delimiter);
        in_file.ignore(100, delimiter);
        in_file >> in_venue.price;
        in_file.ignore(100, delimiter);
        in_file >> in_venue.rating;
        in_file.ignore(100, delimiter);
        in_file.get( in_venue.review, 100, delimiter);
        in_file.ignore(100, delimiter);
        in_file.get( in_venue.category, 30, delimiter);
        in_file.ignore(100, delimiter);


        new_venue.get_venue(in_venue);
        my_table.insert(new_venue);

        if(new_venue.meal)
        {
            delete new_venue.meal;
            delete new_venue.name;
            delete new_venue.review;
            delete new_venue.category;
        }

        // Prime the pump
        in_file.get( in_venue.meal, 30, delimiter);
        in_file.ignore(100, delimiter);


        while(in_file && !in_file.eof())
        {
            in_file.get( in_venue.name, 30, delimiter);
            in_file.ignore(100, delimiter);
            in_file >> in_venue.price;
            in_file.ignore(100, delimiter);
            in_file >> in_venue.rating;
            in_file.ignore(100, delimiter);
            in_file.get( in_venue.review, 100, delimiter);
            in_file.ignore(100, delimiter);
            in_file.get( in_venue.category, 30, delimiter);
            in_file.ignore(100, delimiter);


            new_venue.get_venue(in_venue);
            my_table.insert(new_venue);

            if(new_venue.meal)
            {
                delete new_venue.meal;
                delete new_venue.name;
                delete new_venue.review;
                delete new_venue.category;
            }

            // Prime the pump
            in_file.get( in_venue.meal, 30, delimiter);
            in_file.ignore(100, delimiter);

        }

        in_file.close();
        in_file.clear();
    }


    do
    {
        switch(menu())
        {

            case 1:
                // Add new resturant

                break;

            case 2:
                // Remove by meal
                
                break;

            case 3:
                // Remove all based on venue name

                break;

            case 4:
                // Retrieve by meal name (keyword)
                
                break;

            case 5:
                // Display all information for a particular 
                
                break;

            case 6:
                // Quit
                 quit = true;
                 break;
        }
    }while(!quit);
    
    return 0;
}
