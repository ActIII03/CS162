//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "routes.h"

struct prim_route_qnode
{
    routes * prim_routes;
    prim_route_qnode * next;
};

struct alt_route_qnode
{
    routes * alt_route;
    alt_route_qnode * next;

};


class queue
{
    public:

        //Constructor and destructor
        queue();
        ~queue();

        //Add route to front of CLL
        int enqueue(routes & add_route); //<-- Add argument

        //Remove route from 
        int dequeue(routes & remove_route); //<-- Add argument
        int peek(); //<-- Add argument
        int is_empty();

    private:

            prim_route_qnode * p_rear;
            alt_route_qnode * a_rear;
};

