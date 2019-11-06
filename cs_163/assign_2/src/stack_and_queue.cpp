//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "stack_and_queue.h"

stack::stack()
{
    head = NULL;
    top_index = 0;
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


int stack::push(char q_1[], char a_1[], char q_2[], char a_2[], char q_3[], char a_3[])  
{
    int arr_size = 5;
    int MAX = 5;

    //Update top_index
    if(!head)   //Base case: Allocate mem for queue obj
    {
        head = new node;
        head -> next = NULL;
        head -> card_arr = new queue[arr_size];   //Am I allocating memory for queue obj?
        head -> card_arr[top_index].enqueue(q_1, q_2, q_3, a_1, a_2, a_3);
        ++top_index;
    }
    else if(top_index < MAX)  //Increment here
    {
        head -> card_arr[top_index].enqueue(q_1, q_2, q_3, a_1, a_2, a_3);
        ++top_index;
    }

    else if(top_index == 5)  //Eval top_index and create new node *ADD at head*
    {
        node * temp = head;
        head = new node;
        head -> next = temp;
        head -> card_arr = new queue[arr_size];
        head -> card_arr[top_index].enqueue(q_1, q_2, q_3, a_1, a_2, a_3);
        top_index = 1;
    }

    return 0;
}

queue * stack::pop()
{
    //return card_arr[] -> head
    if(!head)
       return NULL;


    
    return (head -> card_arr); //return the queue ptr
}

queue * stack::peek()
{

    //Implement Peek here by looking at 
    if(!head)
        return NULL;
    queue * temp = head;

    temp -> card_arr[


}
bool stack::is_empty()
{

    if(!head)
        return false;

    return true;

}

int stack::is_full()
{

    return 0;

}

int queue::enqueue(char q_1[], char q_2[], char q_3[], char a_1[], char a_2[], char a_3[])
{

    //Check for !rear (if-state)
    //Make 1 node and point to itself
    //Create 1 of 3 node
    if(!rear)
    {
        rear = new q_node;
        rear -> next = NULL;
        rear -> question = new char[strlen(q_1)+1];
        strcpy(rear -> question, q_1);
        rear -> answer = new char[strlen(a_1)+1];
        strcpy(rear -> answer, a_1);
    }
    
    //otherwise add to end of CLL
    else
    {
        //Create nodes to add after first node
        q_node * temp = rear;
        rear -> next = new q_node;
        rear = rear -> next;
        rear -> next = temp;
        rear -> question = new char[strlen(q_2)+1];
        strcpy(rear -> question, q_2);
        rear -> answer = new char[strlen(a_2)+1];
        strcpy(rear -> answer, a_2);

    }

    return 0;
}

int queue::dequeue()
{
    //Check !rear

    return 0;
}

int queue::isempty()
{
    //Stub
    if(rear)
        return 1;
    return 0;
}

int queue::isfull()
{
    //Stub
    if(rear)
        return 1;
    return 0;
}


int queue::display_pub()
{
    if(!rear)
        return 0;
    int value = 0;
    value = display(rear);
    
    return value;
}

int queue::display(q_node * rear)
{

    if(!rear)
        return 0;
    int number = 1;
    q_node * temp = rear;
    do
    {
        cout << "Question (" << number++ << "): " << temp->question << endl;
        temp = temp -> next;
    }
    while(temp != rear);

    return 0;
}
