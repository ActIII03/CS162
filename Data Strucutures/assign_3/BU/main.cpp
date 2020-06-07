//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: 

#include "venue.h"
#include "table.h"

int main(void)
{
    int choice = 0, result = 0, temp = 0;

    cout << "What will be the size of the table?: ";
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

        // Destory 
        new_venue.destory();

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

            // Destory 
            new_venue.destory();

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
                cout << "\nEnter the following:\n(1) Meal name: ";
                cin.get(in_venue.meal, 30, '\n');
                cin.ignore(100, '\n');
                cout << "Venue or Food Cart Name: ";
                cin.get(in_venue.name, 30, '\n');
                cin.ignore(100, '\n');
                cout << "\nPrice: ";
                cin >> in_venue.price;
                cin.ignore(100, '\n');
                cout << "\nRating: ";
                cin >> in_venue.rating;
                cin.ignore(100, '\n');
                cout << "Review: ";
                cin.get(in_venue.review, 100, '\n');
                cin.ignore(100, '\n');
                cout << "Category(Venue or Food Cart): ";
                cin.get(in_venue.category, 100, '\n');
                cin.ignore(100, '\n');
                new_venue.get_venue(in_venue);
                result = my_table.insert(new_venue);
                if(!result)
                    cout << "\nSuccessful entry!\n";
                else
                    cout << "\nSomething went wrong, try again!\n";
                // Destory 
                new_venue.destory();
                break;

            case 2:
                // Remove by meal 
                cout << "Please select a meal to remove from list: ";
                cin.get(in_venue.meal, 30, '\n');
                cin.ignore(100, '\n');
                result = my_table.remove(in_venue.meal, 1); //Signifying what type of remove
                if(!result)
                    cout << "\nSuccessful removal!\n";
                else
                    cout << "\nSomething went wrong, try again!\n";
                break;

            case 3:
                // Remove all based on venue name
                cout << "Please enter a venue you want to remove from the list: ";
                cin.get(in_venue.name, 30, '\n');
                cin.ignore(100, '\n');
                result = my_table.remove(in_venue.name, 2);  // <---- Work on & signifying what type of remove
                if(result)
                    cout << "\nRemoved this number of items: " << result << endl;
                else
                    cout << "\nSomething went wrong, try again!\n";
                break;

            case 4:
                // Retrieve by meal (keyword) <-- Work on
                choice = 0;
                do
                {
                    cout << "Pick a meal: ";
                    cin.get(in_venue.meal, 30, '\n');
                    cin.ignore(100, '\n');
                    choice = temp;
                    result = my_table.retrieve(in_venue.meal, new_venue, choice);

                    if(!result)
                        cout << "Something went wrong, try again!\n";

                    else
                    {
                        cout << "Meal: " << new_venue.meal
                             << "\nName of Venue: " << new_venue.name
                             << "\nPrice: " << new_venue.price
                             << "\nRating: " << new_venue.rating
                             << "\nReview: " << new_venue.review
                             << "\nCategory of Venue: " << new_venue.category << endl;

                        ++choice;
                        temp = choice;

                        if(new_venue.meal)
                        {
                            delete new_venue.meal;
                            delete new_venue.name;
                            delete new_venue.review;
                            delete new_venue.category;
                        }
                    }

                    cout << "Wanna keep retrieving?( 1 = Yes & 2 = No): ";
                    cin >> choice;
                    cin.ignore(100, '\n');
                }while(choice == 1);
                break;

            case 5:
                // Display all information for a particular meal choice <-- Work on result
                cout << "\nPlease select a meal to display from list: ";
                cin.get(in_venue.meal, 30, '\n');
                cin.ignore(100, '\n');
                result = my_table.display(in_venue.meal);
                if(result)
                    cout << "\nEither nothing is listed or something went wrong. try again.\n";

                break;

            case 6:
                // Quit
                 quit = true;
                 break;
        }
    }while(!quit);
    
    return 0;
}
