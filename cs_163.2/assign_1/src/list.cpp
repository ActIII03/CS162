//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "list.h"

accessory_node::accessory_node()
{
    name = NULL;
    category = NULL;
    status = NULL;
}

list::list()
{
    head = NULL;
    tail = NULL;
}

list::~list()
{
    

}

int list::insert_room(const SmartHome new_room)
{
    
    //Recursive Call
    int result = insert_room(head, tail, new_room);

    return result;
}


int list::insert_accessory(char  * room, char * accessory_name, char * cat, char * status)
{


    return 0;
}

int list::remove_room(char * room)
{

    return 0;
}

int list::remove_accessory(char * room, char * accessory_name )
{


    return 0;
}

int list::remove_all_accessories(char * room)
{

    return 0;
}

int list::retrieve_room(char * room)
{

    return 0;

}

int list::display_all_accessories()
{

    return 0;
}

int list::traverse_room_list()
{

    return 0;
}

int list::insert_room(room_node * & head, room_node * & tail, const SmartHome new_room)
{
    //Empty list or Insert at the end
    if(!head)
    {
        head = new room_node;
        head -> new_room.room = new char[strlen(new_room.room) + 1];
        strcpy(head -> new_room.room, new_room.room);
        head -> next = NULL;
        head -> access_head = NULL; 
        tail = head;
        return 0;
    }
    
    if(strcmp(head -> new_room.room, new_room.room) < 0)
        insert_room(head -> next, tail, new_room);

    else if(strcmp(head -> new_room.room, new_room.room) > 0)
    {
        room_node * new_node = new room_node;
        new_node -> next = head;
        head = new_node;
        new_node -> new_room.room = new char[strlen(new_room.room) + 1];
        strcpy(new_node -> new_room.room, new_room.room);
        new_node -> access_head = NULL;
        return 0;
    }

    else if(strcmp(head -> new_room.room, new_room.room) == 0)
        return 1;

    return 0;
}

int list::remove_all_accessories(accessory_node * & head)
{

    return 0;
}

int list::retrieve_room(room_node * head)
{


    return 0;
}

/*
 Recursive Function here
int list::display_all_accessories()
{


    return 0;
}

*/
