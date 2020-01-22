//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "smart_home.h"

struct accessory_node
{
    ~accessory_node();
    char * name;
    char * category;
    char * status;
    accessory_node * next;
};

struct room_node
{
    SmartHome new_room;
    room_node * next;
    accessory_node * access_head;
};

class list
{
    public:

        list();
        ~list();

        //Add room node to LLL
        int insert_room(const SmartHome & new_room);

        //Add accesory node to LLL
        int insert_accessory(char * room, char * accessory_name, char * cat, char * status);

        //Remove one room node
        int remove_room(char * room);

        //Remove one accessory node
        int remove_accessory(char * room, char * accessory_name );

        //Display all accessories
        int display_all_accessories(char * room);
        
        //Traverse room LL
        int traverse_room_list();
        
        //Retrieve room node
        room_node * retrieve_room(char * room); 

    private:
       
        //recusrively insert room node
        int insert_room(room_node * & head, room_node * & tail, const SmartHome & new_room);

        //recursively insert accessory node
        int insert_accessory(accessory_node * & head, char * new_acc, char * new_cat, char * new_stat);

        //Recursively remove all accessories
        int remove_all_accessories(accessory_node * & head);

        //Recursively search for room
        room_node * retrieve_room(room_node * head, char * room); 

        //Recursively traverse room
        int traverse_room_list(room_node * head);

        //Recursively remove room
        int remove_room(room_node * & head, char * room);
        
        //Traverse Accessory list
        void traverse_accessory_list(room_node * head);

        room_node * head;
        room_node * tail;
};
