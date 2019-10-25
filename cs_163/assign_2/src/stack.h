//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "trivial_pursuit.h"
#include "queue.h"

class stack
{
    public:

        stack();
        ~stack();
        int push(node * & deck_cards);
        int pop();
        int peek();

    private:

        queue question;
        q_node * rear;

};
