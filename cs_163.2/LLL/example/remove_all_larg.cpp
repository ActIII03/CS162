#include "list.h"

int remove_largest(node * head, int & lrg_int)
{
    if(!head)
        return 0;

    if(head -> data > lrg_int)
        lrg_int = head -> data;
    int count = remove_largest(head -> next, lrg_int);

    if(head -> data == lrg_int)
    {
        node * temp = head -> next;
        delete head;
        head = temp;
        ++count;
    }

    return count;
}
