#include "cs163_list.h"
using namespace std;




//Implement these three functions
//Add to the end of the LLL as efficiently as possible
int list::add(journal_entry & to_add)
{
    //Empty list
    if(!head)
    {
        head = new node;
        head -> next = NULL;
        head -> entry.copy_entry(to_add);
        tail = head;
        return 0;
    }
    
    node * current = head;

    //One item in our LLL
    if(!current -> next)
    {
        current -> next = new node;
        current = current -> next;
        current -> entry.copy_entry(to_add);
        current -> next = NULL;
        tail = current;
        return 0;
    }
    else
    {
        while(current -> next)
            current = current -> next;

        current -> next = new node;
        current = current -> next;
        current -> entry.copy_entry(to_add);
        current -> next = NULL;
        tail = current;
    }
    return 0;
        
}

//Display all journal entries
//Return false if there are no entries
int list::display(void)
{
         //Your code goes here!
    if(!head)
        return 1;

    node * current = head;
    while(current)
    {
        current -> entry.display();
        current = current -> next;
    }
    return 0;
}

//Determine if there is a match with the title passed in
//and if so provide the matching journal entry back to the
//client program through the second argument.
//Return a zero if no match is found
int list::find(char matching_title[], journal_entry & found)
{
	//Your code goes here!           
    node * current = head;

    while(current)
    {
        if(!current -> entry.retrieve(matching_title, found))
            return 1;
        current = current -> next;
    }

   return 0;
}


//Copy the list passed in as an argument
//and add the nodes to the end of the current list
int list::append(list & source)
{
    if(!head)
    {
        head = new node;
        head -> source.copy_entry(source);
        head -> next = NULL;
        tail = head;
        return 0;
    }
    else if(!head -> next)
    {
        head -> next = new node;
        tail = head -> next;
        tail -> entry.copy_entry(source);
        tail -> next = NULL;
        return 0;
    }
    else
    {
        node * current = head;
        while(current -> next)
            current = current -> next;
        current -> entry.copy_entry(source);
        current -> next = NULL;
        tail = current
    }

    return 0;
}
