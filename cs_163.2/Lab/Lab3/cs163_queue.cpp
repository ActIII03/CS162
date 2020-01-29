#include "cs163_queue.h"


//Implement these functions using a Circular Linked List
//Add at the rear
int queue::enqueue(const journal_entry & to_add)
{
	//Write the function here

    //Emtpy List
    if(!rear)
    {
        rear = new q_node;
        rear -> entry.copy_entry(to_add); 
        rear -> next = rear;
    }

    //One item
    else
    {
       q_node * temp = rear -> next;
       rear -> next = new q_node;
       rear = rear -> next;
       rear -> entry.copy_entry(to_add);
       rear -> next = temp;
    }
    return 0;
}

//Remove the node at the front
int queue::dequeue ()
{
    if(!rear)
        return 0;
    
    if(rear -> next == rear)
    {
        delete rear;
        rear = NULL;
    }
    else
    {
        q_node * temp = rear -> next -> next;
        delete rear -> next;
        rear -> next = temp;
    }
    return 1;
}

