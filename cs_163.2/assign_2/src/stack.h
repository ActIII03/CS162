//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "routes.h"

struct node
{
    routes * route_entries;
    node * next;
};

class stack
{
    public:
        
        //Constructor and destructor
        stack();
        ~stack();

        //Add to stack
        int push(const routes & new_route);

        //Remove from stack
        int pop(void);

        //View recent addition to stack
        int peek(routes & found_route) const;

    private:

        node * head;
        int top_index;
};
