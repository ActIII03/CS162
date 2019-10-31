#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);
    
    int num_arr[5] = { 20, 40, 60, 80, 100 };
    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int count = 0, last_node, even_aver = 0, sum = 0;
    count = count_first(head);
    cout << "First Node's number: " << head -> data << " appeared this number of times: " << count << endl;
    
    //count = count_last(head, last_node);
    //cout << "Last Node's number: " << last_node << " appeared this number of times: " << count << endl;

    //count = is_bigger_than_four(head);
    //cout << "Number of data mbr. greater than four: " << count << endl;

    //switch_first_last(head);
    //insert_arr_to_LLL(head, num_arr);
    //remove_last_two(head);
    //remove_every_two(head);
    //copy_LLL_to_arr(head);
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

int switch_first_last(node * & head)
{
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
    return 0;
}

int insert_arr_to_LLL(node * & head, const int num_arr[])
{

    int index = 0;

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
    }
}

int copy_LLL_to_arr(node * head)
{

    int count = 0, index = 0;

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
    cout << "\n";

    //Print array
    for(index = 0; index < count; ++index)
        cout << "Array Number: " << lll_arr[index] << " Index: " << index << endl;
    
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

        return 0;
    }
}

int average_even(node * head)
{
    int even_aver = 0, count = 0;

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
