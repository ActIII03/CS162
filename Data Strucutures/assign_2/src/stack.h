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
        int push(routes & new_route);

        //Remove from stack
        int pop(routes & return_route);

        //Peek
        int peek(routes & display);

        //Display
        int display();

    private:

        //Destructor help
        void destory(node * & head);

        node * head;
        int top_index;
        int MAX;
};
