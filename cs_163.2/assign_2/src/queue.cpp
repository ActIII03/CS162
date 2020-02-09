//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "queue.h"

queue::queue()
{
    p_rear = NULL;
    a_rear = NULL;
}

queue::~queue()
{

}

route_qnode::route_qnode()
{
    next = NULL;
}


int queue::enqueue(routes & add_route, const int route_choice)
{
    int result = 0;
    
    if(!route_choice)
        result = enqueue(p_rear, add_route);
    else
        result = enqueue(a_rear, add_route);

    return result;
}

int queue::enqueue(route_qnode * & rear, routes & add_route)
{
    int result = 0;

    route_qnode * current = rear;

    //Add to front of CLL
    //No items
    if(!rear)
    {
        rear = new route_qnode;
        result = rear -> route_entries.copy_route(add_route); 
        rear -> next = rear;
        return result;
    }
    //One Item
    else if(current -> next == rear)
    {
        route_qnode * new_qnode = new route_qnode;
        new_qnode -> next = rear;
        result = new_qnode -> route_entries.copy_route(add_route);
        rear -> next = new_qnode;
        return result;
    }
    //More than one item
    else 
    {
       route_qnode * temp = rear -> next;
       rear -> next = new route_qnode;
       rear -> next -> next = temp;
       temp = rear -> next;
       result = temp -> route_entries.copy_route(add_route);
       return result;
    }


}

int queue::dequeue(routes & remove_route, int route_choice)
{
    //Empty list
    if( !(p_rear) && !(a_rear) )
        return -99;
   
    int count = 0;

    //Compare route choice and dequeue accordingly
    if(route_choice != 2)
    {
        count = dequeue(p_rear, p_rear -> next, remove_route, route_choice);
        dequeue(a_rear, a_rear -> next, route_choice);
    }
    else
    {
        count = dequeue(a_rear, a_rear -> next, remove_route, route_choice);
        dequeue(p_rear, p_rear -> next, route_choice);
    }

    return count;
}

int queue::dequeue(route_qnode * & rear, route_qnode * & current, routes & out_route, int route_choice)
{

    //Empty list
    if(!rear)
        return 0;

    //One item
    if(rear -> next == rear)
    {
        //Work on destructors
        out_route.copy_route(rear -> route_entries);
        delete rear;
        rear = NULL;
        return 0;
    }

    //Track number of routes remaining
    int count = 0;

    //Traversed to the item behind rear
    if(current -> next == rear)
    {
        out_route.copy_route(rear -> route_entries);
        current -> next = rear -> next;
        delete rear;
        rear = current;
        return 1;
    }

    ++count;
    count += dequeue(rear, current -> next, out_route, route_choice);

    return count;
}

void queue::dequeue(route_qnode * & rear, route_qnode * & current, int route_choice)
{

    //Empty list
    if(!rear)
        return;

    //One item
    if(rear -> next == rear)
    {
        //Work on destructors
        delete rear;
        rear = NULL;
        return;
    }

    //Traversed to the item behind rear
    if(current -> next == rear)
    {
        current -> next = rear -> next;
        delete rear;
        rear = current;
        return;
    }

    dequeue(rear, current -> next, route_choice);

    return;
}

int queue::peek(routes & p_route, routes & a_route)
{
   
    if(p_rear)
        p_route.copy_route(p_rear -> route_entries);
    if(a_rear)
        a_route.copy_route(a_rear -> route_entries);

    return 0;
}

int queue::display(int route_choice)
{
    if( !(p_rear) && !(a_rear) )
        return -99;
    
    if(route_choice == 1)
        display(p_rear, p_rear);
    else
        display(a_rear, a_rear);

    return 0;
}

int queue::display(route_qnode * rear, route_qnode * & current)
{
    if(current -> next == rear)
    {
        current -> route_entries.display();
        return 1;
    }

    current -> route_entries.display();
    display(rear, current -> next);
    return 0;
}
