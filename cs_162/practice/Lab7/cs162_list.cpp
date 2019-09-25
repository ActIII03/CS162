#include "cs162_list.h"

//These are the functions you will be writing
//Everything else has already been written for you!

//Constructor
list::list()
{
     //Step 3 - Implement the constructor here
    head = NULL;
    
}


//Display all items in a linear linked list
void list::display_all()
{
     //Step 5 - Implement the display_all function here
    node * current = head;

    while(current)
    {
        cout << "Data: " << current->data << endl;
        current = current -> next;
    }
}


//Count the number of times the first node's data appears
//in the list, and return that count.
int list::count_first()
{
     //Step 6 - Implement the count_first here
     //(remember to return the count!
    int first = 0, count = 0;
    node * temp = NULL;
   
    if(!head)
        return 0;

    else
    {
        first = head ->data;
        temp = head -> next;
        
        while(temp != NULL)
        {
            if(temp->data == first)
                ++count;
            temp = temp -> next;
        }
      
        cout << first << " appears " << count << " times.\n";

        return count;
    }
}

//Display the LAST node's data
void list::display_last()
{
    //Step 7 - Place your code here
    node * current = head;
    int last = 0;

    if(head)
    {
        last = head -> data;
        while(current )
        {
            last = current -> data;
            current = current -> next;
        }

        cout << last << " is the last node in the list.\n";
    }
}

//Return true if the last node's data appears
//in the list more than once.
bool list::find_last()
{
    //Step 8 - Place your code here

}
