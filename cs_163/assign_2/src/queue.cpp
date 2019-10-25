//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "queue.h"

q_node::q_node()
{
    next = NULL;
}

q_node::q_node()
{

    if(next)
        next = NULL;

}

queue::queue()
{
    question_1 = NULL;
    question_2 = NULL;
    question_3 = NULL;
    answers_1 = NULL;
    answers_2 = NULL;
    answers_3 = NULL;

}

queue::~queue()
{
    if(question_1)
        question_1 = NULL;

    if(question_2)
        question_2 = NULL;

    if(question_3)
        question_3 = NULL;

    if(answer_1)
        answer_1 = NULL;

    if(answer_2)
        answer_2 = NULL;

    if(answer_3)
        answer_3 = NULL;

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
