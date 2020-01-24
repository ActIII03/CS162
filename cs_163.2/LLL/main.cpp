#include "list.h"

int main()
{
    node * head = NULL;
    build(head);
    display(head);
    copy_into_array(head); 
    destroy(head); 
    return 0;
}


int sum_data(node * head, int & sum)
{
    if(!head)
        return 0;
    int count = sum_data(head -> next, sum);
    ++count;
    sum += head -> data;
    return count;
}

int copy_into_array(node * head)
{

    if(!head) 
        return 0;
    int count = count_nodes(head);
    int index = 0;
    int int_arr[count];
    copy_into_array(head, int_arr, index); 

    cout << "Number of items: " << count << endl;
    for(index = 0; index < count; ++index)
        cout << "(" << (index + 1) << ") " << int_arr[index] << endl;
    
    return count;
}

int copy_into_array(node * head, int int_arr[], int & index)
{
    if(!head)
        return 0;
    int_arr[index] = head -> data;
    ++index;
    copy_into_array(head -> next, int_arr, index);
    return 0;
}

int count_nodes(node * head)
{
    if(!head)
        return 0;
    int count = count_nodes(head -> next);
    ++count;
    return count;
}
