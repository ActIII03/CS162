#include "list.h"

int main()
{
    node * head = NULL;
    build(head);
    display(head);
    
    int count = copy_arr_to_LLL(head);
    cout << "Number of items traversed: " << count << endl;

    display(head);
    return 0;
}

int remove_every_other(node * & head)
{
    if(!head)
        return 0;
    if(!head -> next)
    {
        head -> next = NULL;
        return 0;
    }
    int count = 0;
    node * temp = head -> next;
    head -> next = temp -> next;
    delete temp;
    ++count;
    count += remove_every_other(head -> next);
    return count;
}

int copy_arr_to_LLL(node * & head)
{
    if(!head) 
        return 1;
    int int_arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int index = 0;
    int count = traverse(head, int_arr, index);

    return count;
}

int copy_arr_to_LLL(node * & head, int arr[], int & index, int & num_of)
{
    if(num_of == 1)
    {
        head -> next = new node;
        node * temp = head -> next;
        temp -> data = arr[index];
        temp -> next = NULL;
        return 0;
    }

    head -> next = new node;
    node * temp = head -> next;
    temp -> data = arr[index];
    ++index;
    --num_of;
    copy_arr_to_LLL(head -> next, arr, index, num_of);
    return 0;
}

int traverse(node * & head, int arr[], int & index)
{
    int num_of = 10;

    if(!head -> next)
    {
        copy_arr_to_LLL(head, arr, index, num_of);
        return 1;
    }
    int count = traverse(head -> next, arr, index);
    ++count;
    return count;
}
