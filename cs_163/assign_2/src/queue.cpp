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

int queue::enqueue(question & add_question, answer & add_answer)
{

    if(!rear)
    {
        //Create 1 of 3 node
        rear = new q_node;
        rear -> next = NULL;
        temp = rear;
        copy_to(add_question, add_answer, temp);

        //Create 2 of 3 node
        rear = new q_node;
        rear -> next = NULL;
        temp = rear;
        copy_to(add_question, add_answer, temp);


        //Create 3 of 3 node

        return 0;
    }


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

int copy_to(question & copy_q, answer & copy_a) //Pass ptr by ref
{
   char * q_1 = new char[strlen(copy_q.question_1) + 1];
   strcpy(q_1

