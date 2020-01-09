#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    node * dest = NULL;
    build(head);
    display(head);

    //Functions here

    //Count nodes
    //int count = count_first(head -> next, head -> data);
    //cout << "Number of times first node appeared in our LLL: " << count << endl;

    //Count last node
    //int count = count_last(head);
    //cout << "Number of times last node appeared in our LLL: " << count << endl;

    int sum = sum_data(head);
    cout << "Sum of data: " << sum << endl;

    destroy(head); 
    return 0;
}

int sum_data(node * head)
{
    int sum = sum_data_min_arg(head);
    return sum;
}

int count_first(node * head, int & first_node)
{
    int count = count_first_rec(head, first_node);

    /*
    node * current = head;

    while(current)
    {
        if(current -> data == first_node)
            ++count;
        current = current -> next;
    }
    */

    return count;
}

int count_first_rec(node * head, int & first_node)
{

    if(!head)
        return 0;
    if(head -> data == first_node)
        return 1 + count_first_rec(head -> next, first_node);
    else
        count_first_rec(head -> next, first_node);
}

int count_last(node * head)
{

    int count = 0, last_node = 0;
    count_last_rec(head, last_node, count);

    /*
    node * current = head;

    while(current -> next)
        current = current -> next;
    last_node = current -> data;

    current = head;
    
    while(current -> next)
    {
        if(current -> data == last_node)
            ++count;
        current = current -> next;
    }
    */


    return count;
}

void count_last_rec(node * head, int & last_node, int & count)
{
    if(!head -> next)
    {
        last_node = head -> data;
        return;
    }

    count_last_rec(head -> next, last_node, count);

    if(head -> data == last_node)
        ++count;

}

int sum_data_min_arg(node * head)
{
    if(!head)
        return 0;

    int sum = sum_data_min_arg(head -> next);
    sum += head -> data;
    return sum;
}
