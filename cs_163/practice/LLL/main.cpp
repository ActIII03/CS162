#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);
    
    int num_arr[5] = { 20, 40, 60, 80, 100 };
    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int count = 0, last_node=0, even_aver = 0, sum = 0;
    //count = count_first(head);
    //cout << "First Node's number: " << head -> data << " appeared this number of times: " << count << endl;
    
    //count = count_last(head, last_node);
    //cout << "Last Node's number: " << last_node << " appeared this number of times: " << count << endl;

    //count = is_bigger_than_four(head);
    //cout << "Number of data mbr. greater than four: " << count << endl;

    //switch_first_last(head);
    //insert_arr_to_LLL(head, num_arr);
    //remove_last_two(head);
    //remove_every_two(head);
    copy_LLL_to_arr(head);
    //even_aver = average_even(head);
    //cout << "Average of Even data mbr.: " << even_aver << endl;
    //sum = sum_data(head, count);
    //cout << "Sum: " << sum << " Number of items sum'd: " << count << endl;

    display(head); //redisplay the list after your function
    destroy(head); 
    return 0;
}

int count_first(node * head)
{
    int first_node = head -> data, count = 0;

    count = count_first_rec(head, first_node);

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

int count_last(node * head, int & last_node)
{
    int count = 0;
    count_last_rec(head, last_node, count);
    /*
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
    }*/

        return count;
}

int is_bigger_than_four(node * head)
{
    int count = 0; 

    is_bigger_than_four_rec(head, count);
    /*
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
    }*/

    return count;
}

int switch_first_last(node * & head)
{
   // int first_node = head -> data;
    //switch_first_last_rec(head, first_node);
    //switch_first_last_rec(head, &head->data);
    

    /*
    //Empty List
    if(!head)
        return 0;
    else
    {
        node * current = head->next;
        node * temp = head;

        //One item
        if(!head->next)
        {
            return 0;
        }
        
        //Two items
        if(!head->next->next)
        {
            head = current;
            current->next = temp;
            temp->next = NULL;
        }

        //Multiple Items
        else
        {

            //Traverse to last node
            while(current->next)
                current = current->next;

            //Advance head ptr to 2nd node
            head = head -> next;
            current->next = temp;
            temp->next = NULL;

        }
    }
    */
    return 0;
}

int insert_arr_to_LLL(node * & head, const int num_arr[])
{

    int index = 0;
    insert_arr_to_LLL(head, num_arr, index);

    /*
    //Empty list
    if(!head)
    {
        node * n_node = new node;
        node * current = n_node; 
        //Insert into 1st node
        n_node->data = num_arr[index];
        ++index;
        head = n_node;

        while(index < 5)
        {
            node * n_node = new node;
            n_node->data = num_arr[index];
            current->next = n_node;
            current = n_node;
            ++index;
        }
        
        current->next = NULL;
        return 0;
    }

    //One item
    if(!head->next)
    {

        node * n_node = new node;
        node * current = head;
        current->next = head;
        current = n_node;
        n_node->data = num_arr[index];
        ++index;

        while(index < 5)
        {
            node * n_node = new node;
            n_node->data = num_arr[index];
            current->next = n_node;
            current = n_node;
            ++index;
        }

        current->next = NULL;
        return 0;
    }

    //More than one item
    else
    {

        node * current = head;

        //Traverse to last node
        while(current->next)
            current = current->next;
    
        node * n_node = new node;
        n_node->data = num_arr[index];
        ++index;
        current->next = n_node;
        current = n_node;
        
        //Add num_arr at @ end of LLL
        while(index < 5)
        {
            node * n_node = new node;
            n_node->data = num_arr[index];
            current->next = n_node;
            current = n_node;
            ++index;
        }

        current->next = NULL;
        return 0;
    }*/

    return 0;
}

int copy_LLL_to_arr(node * head)
{

    int count = 0, index = 0;
    count = count_nodes_rec(head);
    int num_arr[count];
    copy_LLL_to_arr_rec(head, num_arr, index);

    /*
    //Count number of nodes
    node * current = head;
    while(current)
    {
        ++count;
        current = current->next;
    }
    
    current = head;
    //Declare an instinate array to copy LLL into
    int lll_arr[count];
    while(index < count)
    {
        lll_arr[index] = current->data;
        ++index;
        current = current->next;
    }
    */

    cout << "\n";
    for(index = 0; index < count; ++index)
        cout << "Array Number: " << num_arr[index] << " Index: " << index << endl;
    

    return 0;
}

int remove_last_two(node * head) 
{
    //Empty list
    if(!head)
        return 0;

    //One item
    if(!head->next)
    {
        delete head;
        head->next = NULL;
    }

    //Two items
    else if(!head->next->next)
    {
        node * current = head->next;
        delete head;
        delete current;
        head->next = NULL;
    }

    //More than two items
    else
    {
        node * current = head;
        node * previous;

        while(current->next->next)
        {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;
        delete current;
        current = previous->next;
        delete current;
        previous->next = NULL;
        
    }

    return 0;
}

int remove_every_two(node * & head)
{
    //Empty List
    if(!head)
        return 0;
    //One item
    else if(!head->next)
    {
        delete head;
        head = NULL;
    }
    //Two items
    else if(!head->next->next)
    {
        node * current = head->next;
        delete current;
        head->next = NULL;
    }
    //More than two items
    else
    {
        node * current = head->next;
        node * previous = head;
        
        //Stops at second to last node
        while(current && current->next)
        {
            previous->next = current->next;
            delete current;
            previous = previous->next;
            current = previous->next;
        }
    }
    return 0;
}

int average_even(node * head)
{
    int even_aver = 0, count = 0;
    
    count = average_even_rec(head, even_aver);
    
    even_aver /= count;

    /*
    //Empty list
    if(!head)
        return 0;
    else
    {
        node * current = head;

        while(current)
        {
            if(current->data % 2 == 0)
            {
                ++count;
                even_aver += current->data;
            }
            current = current->next;
        }

        even_aver /= count;

        return even_aver;
    }
    */
    return even_aver;
}

int sum_data(node * head, int & count)
{
    int sum = 0;
    
    if(!head)
        return 0;
    else
    {
        node * current = head;
        while(current)
        {
            sum += current->data;
            ++count;
            current = current->next;
        }

    }

    return sum;
}
        

//Recursion Solutions
int count_first_rec(node * head, int & first_node)  //Work-on
{
    if(!head)
        return 0;
    else
    {
        if(head -> data == first_node)
        {
            return 1 + count_first_rec(head -> next, first_node);
        }
        else
            return count_first_rec(head -> next, first_node);
    }
}

int count_last_rec(node * head, int & last_node, int & count)
{
    //Base Case:  Empty List
    if(!head)
        return 0;

    //Traverse recursively till last node
    count_last_rec(head->next, last_node, count);

    //Update last_node to save last node's data member 
    if(!head->next)
    {
        last_node = head->data;
        return 0;
    }

    if(last_node == head->data)
    {
        count += 1; 
    }
    return count;
}

int is_bigger_than_four_rec(node * head, int & count)
{
    if(!head)
        return 0;

    is_bigger_than_four_rec(head -> next, count);

    if(head -> data > 4)
      count += 1;
    
    return count;
}

int switch_first_last_rec(node * head, int & first_node)
{
    
    if(!head)
        return 0;

    switch_first_last_rec(head -> next, first_node);

    if(!head->next)
    {
        int temp_tail = head -> data;  //Saves last data mbr in LLL to an int value
        head -> data = first_node;  //Replace tail->data to actual head -> data mbrA
        first_node = temp_tail;
        return 0;
    }

    /*
    if(!tail->next->next)
        previous = tail -> next;
    if(!tail->next)

        return 0;

    node * temp = head -> next;

    switch_first_last_rec(head, tail->next, previous);

    if(!tail -> next) */
}
    
int average_even_rec(node * head, int & even_aver)
{
    if(!head)
        return 0;

    if(head -> data % 2 == 0)
    {
        even_aver += head -> data;
        return average_even_rec(head -> next, even_aver) + 1;
    }
    else
        return average_even_rec(head -> next, even_aver); 

}

int insert_arr_to_LLL(node * & head, const int num_arr[], int & index)
{
    if(!head || index == 5)
        return 0;

    node * temp = new node;
    temp -> data = num_arr[index];
    temp -> next = head;
    head = temp;
    insert_arr_to_LLL(head, num_arr, ++index);
    return 0;
}

int copy_LLL_to_arr_rec(node * head, int num_arr[], int & index)
{
     
    if(!head)
        return 0;

    copy_LLL_to_arr_rec(head -> next, num_arr, index);
    num_arr[index] = head -> data;
    ++index;

    return 0;
}

int count_nodes_rec(node * head)
{
    if(!head)
        return 0;
    return 1 + count_nodes_rec(head -> next);
}
