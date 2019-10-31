//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "queue.h"


queue::queue()
{
    rear = NULL;
}

queue::~queue()
{
    if(rear)
        rear = NULL;
}

q_node::q_node()
{
    answer = NULL;
    question = NULL;
    next = NULL;
}

q_node::~q_node()
{
    if(answer)
        answer = NULL;
    if(question)
        question = NULL;
    if(next)
        next = NULL;
}

int queue::enqueue()
{

    //Stub

    return 0;
}

int queue::dequeue()
{
    //Stub

    return 0;
}

int queue::isempty()
{
    //Stub

    return 0;
}

int queue::isfull()
{
    //Stub

    return 0;
}



int queue::display()
{
    //Stub

    return 0;
}
