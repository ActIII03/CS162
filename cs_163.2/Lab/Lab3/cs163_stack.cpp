#include "cs163_stack.h"


//These are the functions you will be implementing
//for this lab, using a linear linked list of arrays
//as the data structure

//Add a new item to the top of stack
int stack::push(const journal_entry & new_entry)
{

    //Case 1: Is stack empty?
    if(!head)
    {
        head = new node;
        head -> entries = new journal_entry[MAX];
        head -> next = NULL;
        head -> entries[top_index].copy_entry(new_entry);
        ++top_index;
    }
    //Case 2: Is stack's top index less than MAX?
    else if(top_index < MAX)
    {
        head -> entries[top_index].copy_entry(new_entry);
        ++top_index;
    }
    //Case 3: Stack's top index is equal to MAX
    else
    {
        top_index = 0;
        node * temp = head;
        head = new node;
        head -> entries = new journal_entry[MAX];
        head -> next = temp;
        head -> entries[top_index].copy_entry(new_entry);
        ++top_index;
    }
    return 0;
}

//Remove the top of stack
int stack::pop (void)
{

            //Implement the function here

    //Case 1: top index is zero 
    if(!head)
        return 1;

    //Case 2: one item
    if(top_index > 1)
        --top_index;

    //Case 3: top index is one
    else if(top_index == 1)
    {
        node * temp = head;
        head = head -> next;
        delete temp;
        if(head)
            top_index = 5;
        else
            top_index = 0;
    }

    //Case 4: head is null
    else
    {
        top_index = 0;
        delete head;
    }
    return 0;
}

//Supply the journal at the top of stack back to the client
//Return 0 if there are no items
//top_index is one beyond where the top of stack is...
//with no items, top_index is zero
int stack::peek(journal_entry & top_entry) const
{
    if(!head)
        return 0;

    top_entry.copy_entry(head -> entries[top_index]); //opposite of
    
    return 1;
}
