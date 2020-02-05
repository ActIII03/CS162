//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "routes.h"

routes::routes()
{
    street = NULL;
    traffic_stat = NULL;
    notes = NULL;
    source = NULL;
}

routes::~routes()
{
    if(street)
        delete street;
    if(traffic_stat)
        delete traffic_stat;
    if(notes)
        delete notes;
    if(source)
        delete source;
}

int routes::create_route(const dummy_struct & add_route)
{
    street = new char[strlen(add_route.street) + 1];
    strcpy(street, add_route.street);

    return 0;
}

int routes::copy_route(routes & add_routes)
{
    return 0;
}

int menu()
{
    int choice = 0;
    cout << "\nPlease Select -\n(1) Add route (Primary Route or Alternative) \n(2)Start trip (Choosing from the previewed)"
         << "\n(3) Start Return from destination \n(4) Quit \nPick (1-4): " << endl;
    cin >> choice;

    return choice;
}
