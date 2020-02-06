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


int queue::enqueue(routes & add_route, int route_choice)
{
    bool primary = true;
    int result = 0;

    if(primary)
        result = enqueue_rec(p_rear, p_rear -> next, add_route);
    else
        result = enqueue_rec(a_rear, a_rear -> next, add_route);

    return 0;
}

int queue::enqueue_rec(route_qnode * & rear, route_qnode * & current, routes & add_route)
{
    if(!current)

    if(current != rear)

}

int queue::dequeue(routes & remove_route)
{
    return 0;
}

int queue::peek()
{
    return 0;
}

int queue::is_empty()
{
    return 0;
}
