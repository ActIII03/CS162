//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "stack.h"

stack::stack()
{
    head = NULL;
    top_index = 0;
    MAX = 5;
}

stack::~stack()
{

}

int stack::push(routes & new_route)
{
    //Empty list
    if(!head)
    {
        head = new node;
        head -> route_entries = new routes[MAX];
        head -> next = NULL;
        head -> route_entries[top_index].copy_route(new_route);
        ++top_index;
    }
    else if(top_index < MAX)
    {
        head -> route_entries[top_index].copy_route(new_route);
        ++top_index;
    }
    else
    {
        top_index = 0;
        node * temp = head;
        head = new node;
        head -> route_entries = new routes[MAX];
        head -> next = temp;
        head -> route_entries[top_index].copy_route(new_route);
        ++top_index;
    }

    return top_index;
}


int stack::pop(routes & return_route)
{

    //No Stack(s) to pop from --> head is NULL
    if(!head)
        return 1;

    //Top index is one
    if(top_index > 1)
    {
        return_route.copy_route(head -> route_entries[top_index]);
        --top_index;
    }

    //Top index is greater that one
    else if(top_index == 1)
    {
        node * temp = head;
        return_route.copy_route(temp -> route_entries[top_index]);
        head = head -> next;
        delete temp;
        if(head)
            top_index  = 5;
        else
            top_index = 0;
    } 
    //Otherwise, top_index is zero
    else
    {

        top_index = 0;
        delete head;
        head = NULL;
    }
    return 0;
}

int stack::peek(routes & display)
{
    if(!head)
        return 1;

    return 0;

}

int stack::display()
{
    if(!head)
    {
        cout << "Nothing to display!" << endl;
        return 1;
    }
    
    node * current = head;
    
    //Stop display till end of list
    while(current)
    {
        //Display each of the stack's items
        for(int index = 0; index < MAX; ++index)
            current -> route_entries[index].display();
        current = current -> next;
    }

    return 0;
}
