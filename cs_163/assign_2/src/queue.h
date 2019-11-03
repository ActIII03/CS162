//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include <cstdlib>
#include "stack.h"

struct q_node{

    q_node();
    ~q_node();
    char * question;
    char * answer;
    q_node * next;
};


class queue
{

    public:

        queue();
        ~queue();
        int enqueue(question & add_question, answer & add_answer); 
        int dequeue();
        int isempty();
        int isfull();
        int display();

    private:

        q_node * rear;
};
