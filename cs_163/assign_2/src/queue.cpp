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

    //Create 1 of 3 node
    rear = new q_node;
    rear -> next = NULL;
    rear -> question = new char[strlen(add_question.question_1)+1];
    strcpy(rear -> question, add_question.question_1);
    rear -> answer = new char[strlen(add_answer.answer_1)+1];
    strcpy(rear -> answer, add_answer.answer_1);

    //Create 2 of 3 node
    temp = rear -> next;
    rear -> next = new q_node;
    rear = rear -> next;
    rear -> next = temp;
    rear -> question = new char[strlen(add_question.question_2)+1];
    strcpy(rear -> question, add_question.question_2);
    rear -> answer = new char[strlen(add_answer.answer_2)+1];
    strcpy(rear -> answer, add_answer.answer_2);

    //Create 3 of 3 node
    temp = rear -> next;
    rear -> next = new q_node;
    rear = rear -> next;
    rear -> next = temp;
    rear -> question = new char[strlen(add_question.question_3)+1];
    strcpy(rear -> question, add_question.question_3);
    rear -> answer = new char[strlen(add_answer.answer_3)+1];
    strcpy(rear -> answer, add_answer.answer_3);
    
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
