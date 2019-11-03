//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "stack_and_queue.h"

stack::stack()
{
    head = NULL;
}

stack::~stack()
{
    if(head)
        head = NULL;

}

node::node()
{
    next = NULL;
    card_arr = NULL;
}

node::~node()
{
    if(next)
        next = NULL;
}

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


int stack::push(char q_1[], char q_2[], char q_3[], char a_1[], char a_2[], char a_3[])  
{
    //Update top_index
    if(!head)   //Base case: Allocate mem for queue obj
    {
        head = new node;
        head -> next = NULL;
        head -> card_arr = new card_arr[arr_size];
        head -> card_arr[top_index].enqueue(in_question, in_answer);
        ++top_index;
    }
    else if(top_index < MAX)  //Increment here
    {
        head -> card_arr[top_index].enqueue(in_question, in_answer);
        ++top_index;
    }

    //else if(top_index == 5 *OR MAX*)  //Eval top_index
    

    return 0;
}

int stack::pop()
{

    //Stub

    return 0;

}

int stack::peek()
{

    //Stub

    return 0;

}
int stack::is_empty()
{

    return 0;
}

int stack:is_full()
{

    return 0;

}

int queue::enqueue(char q_1[], char q_2[], char q_3[], char a_1[], char a_2[], char a_3[])
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
