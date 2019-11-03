//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "stack.h"

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
    top_index = 0;
    next = NULL;
    arr_size = 5;

}

node::~node()
{
    if(next)
        next = NULL;
}


int stack::push(question & in_questions, answer & in_answers)  
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
        head -> card_arr[top_index}.enqueue(in_question, in_answer);
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
