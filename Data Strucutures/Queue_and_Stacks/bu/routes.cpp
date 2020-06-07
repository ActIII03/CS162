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

int routes::create_route(const a_route & add_route)
{
    street = new char[strlen(add_route.street) + 1];
    strcpy(street, add_route.street);
    length = add_route.length;
    traffic_stat = new char[strlen(add_route.traffic_stat) + 1];
    strcpy(traffic_stat, add_route.traffic_stat);
    notes = new char[strlen(add_route.notes) + 1];
    strcpy(notes, add_route.notes);
    source = new char[strlen(add_route.source) + 1];
    strcpy(source, add_route.source);

    int route_choice = 0;

    cout << "\nNow is this a primary route or back-up to a primary route?( Primary = 0 & Alternative = 1) : ";
    cin >> route_choice;
    cin.ignore(100, '\n');

    return route_choice;
}

int routes::copy_route(routes & add_route)
{
    street = new char[strlen(add_route.street) + 1];
    strcpy(street, add_route.street);
    length = add_route.length;
    traffic_stat = new char[strlen(add_route.traffic_stat) + 1];
    strcpy(traffic_stat, add_route.traffic_stat);
    notes = new char[strlen(add_route.notes) + 1];
    strcpy(notes, add_route.notes);
    source = new char[strlen(add_route.source) + 1];
    strcpy(source, add_route.source);

    return 0;
}

void routes::display()
{
    if(street)
    {
      cout << "\nStreet: " << street
           << "\nDistance (miles): " << length
           << "\nTraffic Status: " << traffic_stat
           << "\nNotes: " << notes
           << "\nSource of information: " << source
           << "\n";
    }
    else
        cout << "\nEntry not found" << endl;
}

int menu()
{
    int choice = 0;
    cout << "\nPlease Select:\n(1) Add route (Primary Route or Alternative) \n(2) Start trip (Choosing from the previewed)"
         << "\n(3) Start Return from destination \n(4) Display Routes \n(5) Display Return Trip \n(6) Quit \nPick (1-6): ";
    cin >> choice;
    cin.ignore(100, '\n');


    return choice;
}
