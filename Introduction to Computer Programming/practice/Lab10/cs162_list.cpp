#include "cs162_list.h"


//These are the functions to implement for this lab
//Like Lab9, we are not using clases here

//Check to see if the desired item is in the list
//Return true if it is found

//We are also practicing with returning values; make
//sure to return values from your functions and use
//those returned values in main!

//Step 2 - Practice Traversal
int display_first_and_last(node * head)
{
    node * current = head;
    int sum = 0;
    if(!head)
        return 0;
    else
    {
        if(head -> next == NULL)
        {
            cout << "Only one node and sum is: " << head -> data << endl;
            return 0;
        }

        else
        {
            cout << "First node: " << head -> data << endl;
            sum += head -> data;

            while(current -> next != NULL)
                current = current -> next;

            cout << "Second node: " << current -> data << endl;
            sum += current -> data;
            cout << "Sum of 1st and last node: " << sum << endl;
            return 0;
        }
    }
}
//Step 3 - Practice Insertion
bool insert_before_last(node * & head, int to_add)
{
           //Write our code here
    if(!head)
        return false;
    else
    {
        //Create after 1st base case
        node * current = head;
        node * temp = new node;
        temp -> data = to_add;

        if(head -> next == NULL)
        {
            temp -> next = head;
            head = temp;
            return true;
        }

        else
        {
            while(current -> next -> next != NULL)
                current = current -> next;

            temp -> next = current -> next;
            current -> next = temp;
            return true;
        }
    }
            
}

//Step 4 - Practice Removal
int remove_first_two(node * & head)
{
          //Write your code here
    if(!head)
        return 1;
    else
    {
        node * current = head;
        int count = 2;

        if(head -> next == NULL)
        {
            delete head;
            cout << "Only one node!\n";
            return 0;
        }

        else
        {
            while(count != 0)
            {
                current = current -> next;
                delete head;
                head = current;
                --count;
            }
            return 0;
        }
    }
}


//Challenge - Make a complete copy  of the entire LLL creating
//a completely new LLL
void copy_all(node * & destination_head, node * source_head)
{
    /* Example code w/ recursion:
     *
     * if(!source_head)
     *      return;
     *  destination_head = new node;
     *  destination_head -> data = source_head -> data;
     *
     *  copy_all(destination_head -> next, source_head -> next); */

    //Iterative approach

    if(source_head == NULL)
        return;
    else
    {

        destination_head = new node;
        destination_head -> data = source_head -> data;
        destination_head -> next = NULL;

        node * current = source_head -> next;

        while(current)
        {
            destination_head -> next = new node;
            destination_head = destination_head -> next;
            destination_head -> data = current -> data;
            destination_head -> next = NULL;
            current = current -> next;
        }
        return;
    }
}
