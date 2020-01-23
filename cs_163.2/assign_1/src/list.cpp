//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "list.h"

accessory_node::~accessory_node()
{
    if(name)
        delete name;
    if(category)
        delete category;
    if(status)
        delete status;
}

list::list()
{
    head = NULL;
    tail = NULL;
}

list::~list()
{
    if(!head)
        head = NULL;
    else
    {
        room_node * current = head;
        while(current)
        {
            head = head -> next;
            if(current -> access_head)
            {
                accessory_node * a_current = current -> access_head;
                while(a_current)
                {
                    current -> access_head =  current -> access_head -> next;
                    delete a_current;
                    a_current = current -> access_head;
                }
            }
            delete current;
            current = head;
        }
        delete head;
        head = NULL;
    }

}

int list::insert_room(const SmartHome & new_room)
{

    //Recursive Call
    int result = insert_room(head, tail, new_room);

    return result;
}


int list::insert_accessory(char  * room, char * accessory_name, char * cat, char * status)
{

    if(!head)
        return 1;
    room_node * current = retrieve_room(room);
    int result = insert_accessory(current -> access_head, accessory_name, cat, status);  
    return result;
}

int list::remove_room(char * room)
{

    int result = remove_room(head, room);
    return result;
}

int list::remove_accessory(char * room, char * accessory_name )
{
    room_node * current = retrieve_room(head, room);
    if(!current)
        return 1;
    //Check if access LLL exist
    if(!head -> access_head)
        return 1;

    accessory_node * a_node = current -> access_head;

    //Head is a match
    if(strcmp(a_node -> name, accessory_name) == 0)
    {
        a_node = a_node -> next;
        current -> access_head -> next = a_node;
        delete current;
    }

    else
    {
        accessory_node * previous;

        do
        {
            previous = a_node;
            a_node = a_node -> next;
            if(strcmp(a_node -> name, accessory_name) == 0)
            {
                previous -> next = a_node -> next;
                delete a_node;
                a_node = previous -> next;
            }

        }while(a_node -> next);

        //Last noide is a match
        if(strcmp(a_node -> name, accessory_name) == 0)
        {
            previous -> next = NULL;
            delete a_node;

        }
    }

    return 0;
}

room_node * list::retrieve_room(char * room)
{
    room_node * current = retrieve_room(head, room);
    return current;

}

int list::display_all_accessories(char * room)
{

    room_node * current = retrieve_room(room);

    //Check if room node exist
    if(!current)
        return 1;
    //Check if access LLL exist
    if(!head -> access_head)
        return 1;

    accessory_node * a_node = current -> access_head;
    while(a_node)
    {
        cout << "\nAccessory: " << a_node -> name
            << "\nCategory: " << a_node -> category
            << "\nStatus: " << a_node -> status << endl;
        a_node = a_node -> next;
    }
    return 0;
}

int list::traverse_room_list()
{

    int result = traverse_room_list(head);
    return result;
}

int list::traverse_room_list(room_node * head)
{
    if(!head)
        return 1;
    cout << "\nRoom: " << head -> new_room.room << endl;
    traverse_accessory_list(head);
    traverse_room_list(head -> next);
    return 0;
}

void list::traverse_accessory_list(room_node * head)
{
    if(!head -> access_head)
        return;

    accessory_node * a_node = head -> access_head;
    while(a_node)
    {
        cout << "\nAccessory: " << a_node -> name
            << "\nCategory: " << a_node -> category
            << "\nStatus: " << a_node -> status << endl;
        a_node = a_node -> next;
    }
    return;


}

int list::insert_room(room_node * & head, room_node * & tail, const SmartHome & new_room)
{
    //Empty list or Insert at the end
    if(!head)
    {
        head = new room_node;
        head -> new_room.copy_entry(new_room);
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
        new_node -> new_room.copy_entry(new_room);
        new_node -> access_head = NULL;
        return 0;
    }

    else if(strcmp(head -> new_room.room, new_room.room) == 0)
        return 1;

    return 0;
}

int list::insert_accessory(accessory_node * & head, char * new_acc, char * new_cat, char * new_stat)
{
    if(!head)
    {
        head = new accessory_node;
        head -> name = new char[strlen(new_acc) + 1];
        strcpy(head -> name, new_acc);
        head -> category = new char[strlen(new_cat) + 1];
        strcpy(head -> category, new_cat);
        head -> status = new char[strlen(new_stat) + 1];
        strcpy(head -> status, new_stat);
        head -> next = NULL;
        return 0;
    }

    if(strcmp(head -> category, new_cat) < 0)
        insert_accessory(head -> next, new_acc, new_cat, new_stat);
    else if(strcmp(head -> category, new_cat) > 0)
    {
        accessory_node * new_node = new accessory_node;
        new_node -> next = head;
        head = new_node;
        head -> name = new char[strlen(new_acc) + 1];
        strcpy(head -> name, new_acc);
        head -> category = new char[strlen(new_cat) + 1];
        strcpy(head -> category, new_cat);
        head -> status = new char[strlen(new_stat) + 1];
        strcpy(head -> status, new_stat);
        head -> next = NULL;
        return 0;
    }
    else
        return 1;

    return 0;
}

room_node * list::retrieve_room(room_node * head, char * room)
{
    if(!head)
        return head;
    if(!head -> new_room.compare_room(room))
        return head;
    retrieve_room(head -> next, room);
}

int list::remove_room(room_node * & head, char * room)
{
    if(!head)
        return 1;
    
    if(strcmp(head -> new_room.room, room) == 0)
    {
        room_node * temp = head -> next;
        remove_all_accessories(head -> access_head);
        delete head;
        head = temp;
        return 0;
    }

    remove_room(head -> next, room);
    return 0;
}

int list::remove_all_accessories(accessory_node * & head)
{
    if(!head)
        return 1;
    accessory_node * temp = head -> next;
    delete head;
    head = temp;
    remove_all_accessories(head);
    return 0;

}
