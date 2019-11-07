//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "stack_and_queue.h"

stack::stack()
{
    head = NULL;
    //card_arr = NULL;
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

    else if(top_index == MAX)  //Eval top_index and create new node *ADD at head*
    {
        node * n_node = new node;
        n_node -> next = head;
        head = n_node;
        top_index = 0;
        n_node -> card_arr = new queue[arr_size];
        n_node -> card_arr[top_index].enqueue(q_1, q_2, q_3, a_1, a_2, a_3);
        top_index = 1;
    }

    return 0;
}

queue * stack::pop()
{
    if(!head)
       return NULL;
   
    queue * n_queue = new queue;
    --top_index;
    q_node * rear = head -> card_arr[top_index].get_rear(); //remove rear and return objects and set rear to null
    //Implemenet a function to copy into n_queue
    n_queue -> set_rear(rear); //Move from source to destination list

    return n_queue; //return the queue ptr
}

q_node * queue::get_rear()
{

    if(!rear)
        return NULL;
    q_node * temp = rear;
    //rear = NULL;

    return temp;

}

int queue::set_rear(q_node * to_copy)
{
    
    //Copy rear 
    this -> rear = to_copy;

    return 0;

}

void queue::copy(char q_1[], char a_1[], char q_2[], char a_2[], char q_3[], char a_3[]) 
{
 
       strcpy(q_1,  rear -> question); 
       strcpy(a_1,  rear -> answer); 
       strcpy(q_2,  rear -> next -> question); 
       strcpy(a_2,  rear -> next -> answer); 
       strcpy(q_3,  rear -> next -> next -> question); 
       strcpy(a_3,  rear -> next -> next -> answer); 

}

node * stack::peek()
{

    //Implement Peek here by looking at 
    if(!head)
        return NULL;
    node * temp = head;

    //temp -> card_arr[
    return temp;

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
    if(!rear)
    {
        rear = new q_node;
        rear -> question = new char[strlen(q_1)+1];
        strcpy(rear -> question, q_1);
        rear -> answer = new char[strlen(a_1)+1];
        strcpy(rear -> answer, a_1);
    
        //Create nodes to add after first node
        q_node * n_node = new q_node;
        rear -> next = n_node;
        n_node -> next = rear;
        n_node -> question = new char[strlen(q_2)+1];
        strcpy(n_node -> question, q_2);
        n_node -> answer = new char[strlen(a_2)+1];
        strcpy(n_node -> answer, a_2);

        n_node = new q_node;
        n_node -> next = rear -> next;
        rear -> next = n_node;
        n_node -> question = new char[strlen(q_3)+1];
        strcpy(n_node -> question, q_3);
        n_node -> answer = new char[strlen(a_3)+1];
        strcpy(n_node -> answer, a_3);
    }
    
    return 0;
}

int queue::dequeue()
{
    //Check !rear

    return 0;
}

/*
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
}*/


int queue::display_pub(int & question, char answer[])
{
    if(!rear)
        return 0;
    int value = 0;
    value = display(rear, question, answer);
    
    return value;
}

int queue::display(q_node * rear, int & question, char answer[])
{

    if(!rear)
        return 0;
    q_node * temp = rear;

    switch(question){
        case 0:
            cout << "Question (" << (question + 1) << "): " << temp->question << endl;
            strcpy(answer, temp->answer);
            break;
        case 1:
            cout << "Question (" << (question + 1) << "): " << temp->next->question << endl;
            strcpy(answer, temp->next->answer);
            break;
        case 2:
            cout << "Question (" << (question + 1) << "): " << temp->next->next->question << endl;
            strcpy(answer, temp->next->next->answer);
            break;
    }
    return 0;
}
