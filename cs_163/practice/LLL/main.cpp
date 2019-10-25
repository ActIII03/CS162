#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int count = 0, last_node;
    //count = count_first(head);
    //cout << "First Node's number: " << head -> data << " appeared this number of times: " << count << endl;
    
    count = count_last(head, last_node);
    cout << "Last Node's number: " << last_node << " appeared this number of times: " << count << endl;

    count = is_bigger_than_four(head);
    cout << "Number of data mbr. greater than four: " << count << endl;

    display(head); //redisplay the list after your function
    destroy(head); 
    return 0;
}

int count_first(node * head)
{
    int first_node = head -> data, count = 0;

    count = count_first_rec(head->next, first_node);

    /* Iterative
    if(!head) 
        return 0;
    else
    {
        node * current = head -> next;

        while(current)
        {
            if(current -> data == first_node)
                ++count;
            current = current -> next;
        }
    } */

    return count;
}

//Work
int count_first_rec(node * head, int & first_node)
{
    if(!head)
        return 0;
    else
    {
        if(head -> data == first_node)
        {
            count_first_rec(head -> next, first_node);
            return 1;
        }
        else
        {
            count_first_rec(head -> next, first_node);
            return 0;
        }
    }
}

int count_last(node * head, int & last_node)
{
    int count = 0;
    
    //Empty List
    if(!head)
        return 0;

    //One Item
    if(!head -> next)
        return 0 ;
    else
    {
        node * current = head;

        //Traverse to get data value
        while(!current->next)
        {
            current = current -> next;
        }

        last_node = current -> data;
        current = head;  //Reset Current ptr

        //Two items
        if(!current->next->next)
        {
            if(current->next->next->data == last_node)
                return 1;
        }
        
        //More than two items
        else
        {
            //Traverse and compare
            while(current->next)
            {
                if(current->data == last_node)
                    ++count;
                current = current -> next;
            }
        }

        return count;
    }
}

int is_bigger_than_four(node * head)
{
    int count = 0; 
    node * current = head;

    //Empty List
    if(!head)
        return 0;

    //One Item
    else if(!current->next)
    {
        if(current -> data > 4)
            ++count;
        return count;
    }
    
    //Many Items
    else
    {
        while(current)
        {
            if(current->data > 4)
                ++count;
            current = current -> next;
        }

        return count;
    }
}
