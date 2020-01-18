//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "list.h"

int main()
{

    SmartHome room_entry;
    list my_list;
    
    bool quit = false;
    char room[50];

    greetings();

    do
    {
        switch(menu())
        {
            case(1):
                //Add new room
                cout << "\nPlease enter the name of the room you want to enter: ";
                cin.get(room, 50, '\n');
                cin.ignore(100, '\n');
                room_entry.create_room(room); 
                my_list.insert_room(room_entry);
                break;
            case(2):
                //Remove room

                break;
            case(3):
                //Add Accessory to room

                break;
            case(4):
                //Remove a room

                break;
            case(5):
                //Display accessories in a room
                cout << "\nPlease enter a room you want to see all the accessories for: ";
                cin.get(room, "50",'\n');
                cin.ignore(100, '\n');
                break;
            case(6):
                //Display All accessories for all Room
                my_list.traverse_room_list();
                break;
            case(7):
                //Quit
                quit = true;
                break;
        };
    }
    while(!quit);

    return 0;
}
