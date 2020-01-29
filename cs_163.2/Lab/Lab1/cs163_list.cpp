#include "cs163_list.h"
using namespace std;

//Sum  all of the data together in a LLL
int list::sum_total()
{
 	//FIRST do this iteratively here. Then recursively
        //COMMENT out the iterative version when  rewriting
        //the solution recursively
    /*
    int sum = 0;
    node * current = head;
    
    while(current)
    {
        sum += current -> data;
        current = current -> next;
    }

    return sum;
    */

    int sum = sum_total(head);
    return sum;

        //To solve this recursively write another
        //function:   int sum_total(node * head);
        //and call it from this function

}

//Now implement the function recursively!
int list::sum_total(node * head)
{
    //Base case
    if(!head)
        return 0;
    
    //Head recursion
    
    int sum = sum_total(head -> next);
    sum += head -> data;
    return sum;
}

// *************************************************
//Remove the last node in a LLL. Return false if the
//list is empty and nothing is removed
bool list::remove_last()
{
        //Write your code here
        //FIRST do this iteratively here. Then recursively
        /*
        if(!head)
            return false;

        node * current = head;
        node * previous;

        while(current -> next)
        {
            previous = current;
            current = current -> next;
        }

        delete current;
        previous -> next = NULL;
        
        return true;
        */
       
        if(!head)
            return false;

        remove_last(head -> next, tail);
        return true;
        

}

//Now implement the function recursively!
bool list::remove_last(node * & head, node * & tail)
{
    
    if(!head -> next)
    {
        delete head;
        tail -> next = NULL;
        return true;
    }
    
    tail = head;
    remove_last(head -> next, tail);
    return true;
}

// ************************************************
//Remove all nodes in a LLL. Remove false if there is
//nothing to remove
bool list::remove_all()
{
    /*
    if(!head)
        return false;

    node * current = head -> next;
    while(current)
    {
        delete head;
        head = current;
        current = current -> next;
    }
    head = NULL;
    tail = NULL;
    return true;
    */


    if(!head)
        return false;

    bool result = remove_all(head);
    return result;
}

//Now implement the function recursively!
bool list::remove_all(node * & head)
{
    if(!head)
        return false;

    remove_all(head -> next);
    delete head;
    head = NULL;
    return true;
}


// ************************************************
//Return true if the requested item (sent in as an argument)
//is in the list, otherwise return false
bool list::find_item(int item_to_find)
{
        //Write your code here
    
    //Empty list
    if(!head)
        return false;
    
    /*
    //First item is the match
    if(head -> data == item_to_find)
        return true;
    
    node * current = head -> next;
    while(current)
    {
        if(current -> data == item_to_find)
            return true;
        current = current -> next;
    }
    return false;
    */

    bool result = find_item(head, item_to_find);
    return result;
}

//Now implement the function recursively!
bool list::find_item(node * head, int item_to_find)
{
    if(!head)
        return false;
    //Tail recursion
    if(head -> data == item_to_find)
        return true;
    bool result = find_item(head -> next, item_to_find);
    return result;
}


// ************************************************
//Make a complete copy of a LLL
bool list::copy(list & from)
{
    if(!from.head)
        return false;
    bool result = copy(head, tail, from.head);
    return result;

        //Write your code here
    /*
    if(!from.head)
        return false;

    //Copy from -> head to this list's head
    head = new node;
    head -> data = from.head -> data;
    node * current = head;
    node * from_current = from.head -> next;
    while(from_current)
    {
        current -> next =  new node;
        current = current -> next;
        current -> data = from_current -> data;
        from_current = from_current -> next;
    }

    current -> next = NULL;
    node * tail = current;
    return true;
    */

}

//Now implement the function recursively
bool list::copy(node * & dest_head, node * & dest_tail, node * source)
{
    if(!source)
    {
        dest_head = dest_tail = NULL;
        return true;
    }

    else
    {
        dest_head = new node;
        dest_head -> data = source -> data;
    }

    if(!source -> next)
        dest_tail = dest_head;

    return copy(dest_head -> next, dest_tail, source -> next);
}
