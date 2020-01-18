//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;


class SmartHome
{

    public:
    
        SmartHome();
        ~SmartHome();

        //Get character input from user for creating a room
        int create_room(char * new_room);
    
        //Copy into 
        int copy_entry(SmartHome new_room);

        //Get character input for accessory creation
        int create_access(char * name, char * category, char * status);
        
        //Retrieve room for: (1) Delete a room (2) Remove a room  
        int retrieve_room(char * room);

        //Retrieve accessory for: (1) Delete a accessory from a room 
        int retrieve_accessory(char * room, char * access);

        char * room;
};

void greetings();
int menu();
