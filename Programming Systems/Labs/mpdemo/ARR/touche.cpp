#include "arr.h"

int table::display_arr()
{
    if(!head)
        return 0;
    int index = 0;
    return display_arr(head, index);
}

int table::display_arr(node ** head, int & index)
{
    int count = 0;
    if(!head)
        return count;
    else if(index == size)
        return count;

    count += display(*head);
    ++index;
    return count + display_arr(head + index, index);
}

int table::display(node * head)
{
    int count = 0;
    if(!head)
        return count;
    cout << "Data: " << head -> data << endl;
    return count + 1 + display(head -> next);
}

int table::average_even(table & new_arr)
{
    if(!head)
        return 0;
    new_arr.size = this -> size;
    new_arr.head = new node * [new_arr.size];
    int index = 0;
    float sum = 0;
    int count = average_even(this -> head, new_arr.head, index, sum);
    return sum / count;
}

int table::average_even(node ** source, node ** dest, int & index, float & sum)
{
    int count = 0;

    if(index == this -> size)
        return count;

    count += average_even(*source, *dest, sum);
    ++index;
    return count + average_even(source + 1, dest + 1, index, sum);
}

int table::average_even(node * source, node *& dest, float & sum)
{
    int count = 0;

    if(!source)
        return count;

    if(source -> data % 2 == 0)
    {
        dest = new node;
        dest -> data = source -> data;
        dest -> next = NULL;
        sum += dest -> data;
        ++count;
        count += average_even(source -> next, dest -> next, sum);
    }
    else
        count += average_even(source -> next, dest, sum);
    return count;
}

int table::all_unique()
{
    if(!head)
        return 0;
    return all_unique(head);
}

int table::all_unique(node * head[])
{
    int index = 0;
    return traverse_ARR(head, index);
}

int table::traverse_ARR(node ** head, int & index)
{
    if(index == size)
        return 0;

    int sub_count = traverse_LLL(*head);

    int count = traverse_ARR(++head, ++index);

    if(sub_count > count)
        return sub_count + 1;
    return count; 

}

//Traverse LLL
int table::traverse_LLL(node * head)
{
    if(!head)
        return 0;

    //Traverse from this element
    int sub_count = traverse_unique(head -> next, head -> data);

    //compare return value
    int count = traverse_LLL(head -> next);

    if(sub_count > count)
        return sub_count + 1;

    return count;

}

//Is unique traverse (sub-traversal )
int table::traverse_unique(node * head, int search)
{
    if(!head)
        return 0;
    
    int count = traverse_unique(head -> next, search);
    
    //Compare after head recursion
    if(head -> data == search)
        ++count;
    return count;

}

int table::remove_last_LLL()
{
    if(!head)
        return 0;
    return remove_last_LLL(head[size - 1]);
}

int table::remove_last_LLL(node *& current)
{
    int count = 0;

    if(!current)
        return count;
    
    count += remove_last_LLL(current -> next);

    delete current;
    current = NULL;

    return count + 1;
}

