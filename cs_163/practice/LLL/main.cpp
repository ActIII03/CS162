#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int count = 0;
    count = count_first(head);
    cout << "First Node's number: " << head -> data << " appeared this number of times: " << count << endl;

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
