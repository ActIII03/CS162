//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "smart_home.h"

SmartHome::SmartHome() 
{
    room = NULL;
}

SmartHome::~SmartHome()
{
    if(room)
    {
        //delete room;
    }
}

int SmartHome::create_room(char * new_room)
{
    
    room = new char[strlen(new_room) + 1];
    strcpy(room, new_room);
    return 0;
}


int SmartHome::retrieve_accessory(char * room, char * access)
{

    return 0;
}

void greetings()
{

    cout << "Welcome to the Smart-home repo which where you can store information in regards to indiividual rooms in your with and all the IoT accessories that are associated with each room." << endl;
}

int menu()
{
    int choice = 0;
    
    cout << "\nPlease choose from the following options:\n"
         << "(1) Add a New Room\n"
         << "(2) Remove a Room\n"
         << "(3) Add a accessory to an existing room\n"
         << "(4) Remove an Accessory from an existing room\n"
         << "(5) Display all Accessories from an existing room\n"
         << "(6) Display all Accessories for all Rooms\n"
         << "(7) Quit\n"
         << "Pick one (1-7): ";
    cin >> choice;
    cin.ignore(100, '\n');

    return choice;
}
