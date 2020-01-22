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
    int result = 0;
    char room[50];
    char accessory[50];
    char category[50];
    char status[50];

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
                result = my_list.insert_room(room_entry);
                if(result)
                    cout << "\nSomething went wrong, try again!" << endl;
                break;
            case(2):
                //Remove room
                cout << "Please enter a room you want deleted from the list: ";
                cin.get(room, 50, '\n');
                cin.ignore(100, '\n');
                result = my_list.remove_room(room);
                if(result)
                    cout << "\nRoom wasn't found or something went wrong, try again!" << endl;
                break;
            case(3):
                //Add Accessory to room
                cout << "Please enter a room to add an accessory to: ";
                cin.get(room, 50, '\n');
                cin.ignore(100, '\n');
                cout << "Please enter the following: "
                     << "\nAcessory name: ";
                cin.get(accessory, 50, '\n');
                cin.ignore(100, '\n');
                cout << "Category of Accessory: ";
                cin.get(category, 50, '\n');
                cin.ignore(100, '\n');
                cout << "Status of Accessory: ";
                cin.get(status, 50, '\n');
                cin.ignore(100, '\n');
                result = my_list.insert_accessory(room, accessory, category, status);
                if(result)
                    cout << "\nRoom wasn't found or something went wrong, try again!" << endl;
                break;
            case(4):
                //Remove a accessory in a room
                cout << "Please enter a room you want to have an acessory deleted from: ";
                cin.get(room, 50, '\n');
                cin.ignore(100, '\n');
                my_list.display_all_accessories(room);
                cout << "Out of the following accessories, which one would you like to delete: ";
                cin.get(accessory, 50, '\n');
                result = my_list.remove_accessory(room, accessory);
                if(result)
                    cout << "\nRoom wasn't found or something went wrong, try again!" << endl;
                break;
            case(5):
                //Display accessories in a room 
                cout << "\nPlease enter a room you want to see all the accessories for: ";
                cin.get(room, 50, '\n');
                cin.ignore(100, '\n');
                result = my_list.display_all_accessories(room);
                if(result)
                    cout << "\nRoom wasn't found or something went wrong, try again!" << endl;
                break;
            case(6):
                //Display All accessories for all Room 
                result = my_list.traverse_room_list();
                if(result)
                    cout << "\nRoom wasn't found or something went wrong, try again!" << endl;
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
