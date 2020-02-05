//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "routes.h"

struct route_qnode
{
    routes * route_entries;
    route_qnode * next;
};

class queue
{
    public:

        //Constructor and destructor
        queue();
        ~queue();

        //Add route to front of CLL
        int enqueue(routes & add_route, int route_choice); //<-- Add argument

        //Remove route from 
        int dequeue(routes & remove_route); //<-- Add argument
        int peek(); //<-- Add argument
        int is_empty();

    private:

        int enqueue_rec(route_qnode * & rear, routes & add_route);
        route_qnode * p_rear;
        route_qnode * a_rear;
};
