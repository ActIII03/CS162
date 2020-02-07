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

    return 0;
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
    if( !(p_rear) || !(a_rear) )
        return -99;
   
    int result = 0;

    //Compare route choice
    if(route_choice != 2)
        result = dequeue(p_rear, p_rear -> next, remove_route, route_choice);
    else
        result = dequeue(a_rear, a_rear -> next, remove_route, route_choice);

    return result;
}

int queue::dequeue(route_qnode * & rear, route_qnode * & current, routes & out_route, int route_choice)
{


    /*
    //One item
    if(rear -> next == rear)
    {
        //Work on destructors
        delete rear;
        rear = NULL;
        return 0;
    }

    int count = 1;

    //Two items remove se


    //Three items remove thirs
    
    //More than three then traverse
    ++count;
    count += dequeue(rear, current -> next, out_route, route_choice);
    */
    int count = 0;


    return count;
}

int queue::peek(routes & p_route, routes & a_route)
{
   
    p_route.copy_route(p_rear -> route_entries);
    a_route.copy_route(a_rear -> route_entries);

    return 0;
}
