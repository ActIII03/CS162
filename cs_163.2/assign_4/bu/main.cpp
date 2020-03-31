//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: 

#include "venue.h"
#include "bst.h"

int main(void)
{

    //ADT and client objects
    table BST;
    Venue new_venue;

    //Buffer
    a_venue in_venue, meal_matches[10];

    int result = 0;
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
        BST.insert(new_venue);

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
            BST.insert(new_venue);

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
                // Add venue
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
                result = BST.insert(new_venue);

                if(!result)
                    cout << "\nSuccessful entry!\n";
                else
                    cout << "\nSomething went wrong, try again!\n";

                // Destory 
                new_venue.destory();

                break;
            case 2:
                // Search a for a particular meal
                cout << "\nPlease enter one meal you would like to search for: ";
                cin.get(in_venue.meal, 30, '\n');
                cin.ignore(100, '\n');

                result = BST.search_meal(in_venue.meal, new_venue);

                if(result)
                    cout << "\nSomething went wrong, try again!";
                else 
                    new_venue.display();

                break;
            case 3:
                // Remove all meal matches
                cout << "\nPlease input a meal name you wish to delete: ";
                cin.get(in_venue.meal, 30, '\n');
                cin.ignore(100, '\n');
                result = BST.remove(in_venue.meal);
                if(!result)
                    cout << "\nEither entry wasn't found or something went wrong, try again!\n";
                else
                    cout << "\nSuccessful removal!" << endl;

                break;
            case 4:
                // Retrieve all meal matches
                cout << "\nPlease enter a meal you wish to what resturant(s) may serve your dish: ";
                cin.get(in_venue.meal, 30, '\n');
                cin.ignore(100, '\n');
                result = BST.display(in_venue.meal, meal_matches, 3);
                if(!result)
                    cout << "\nSomething went wrong or no entries, try again!\n";
                else
                {
                    for(int index = 0; index < result && index < 10; ++index)
                    {
                        cout << "\nMeal: " << meal_matches[index].meal
                             << "\nVenue Name: " << meal_matches[index].name
                             << "\nPrice: " << meal_matches[index].price
                             << "\nRating: " << meal_matches[index].rating
                             << "\nReview: " << meal_matches[index].review
                             << "\nType of Venue: " << meal_matches[index].review << endl;
                    }

                    if(result == 9)
                        cout << "\nMaxium number of retrieves was reached. Sorry... try the \"Display\" all option to get a better list" << endl;
                }

                break;
            case 5:
                //Display all meal matches
                cout << "\nPlease a enter a meal name to see if there are multiple entries: ";
                cin.get(in_venue.meal, 30, '\n');
                cin.ignore(100, '\n');

                result = BST.display(in_venue.meal, meal_matches, 1);

                if(result)
                    cout << "\nNumber of entries: " << result << endl;
                else
                    cout << "\n Something went wrong, try again!" << endl;

                break;
            case 6:
                // Display sorted order
                result = BST.display("N/A", meal_matches, 2);

                if(!result)
                    cout << "Something went wrong, try again!" << endl;

                break;
            case 7:
                // Get height
                cout << "\nHeight of BST: " << BST.get_height() << endl;

                break;
            case 8:
                // Is efficient

                result = BST.is_efficient();
                if(!result)
                    cout << "\nBST isn't balanced, thus not efficient" << endl;
                else
                    cout << "\nBST is reasonably balanced!" << endl;

                break;
            case 9:
                // Quit
                quit = true;

                break;
        }
    }while(!quit);

    cout << "\nThank you, come again!" << endl;

    return 0;
}
