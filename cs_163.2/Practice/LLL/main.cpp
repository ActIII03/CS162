#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    node * dest = NULL;
    build(head);
    display(head);

    int result = remove_last_node(head);
    if(!result)
        cout << "Success!" << endl;
    else
        cout << "Failure!" << endl;

    display(head);
    destroy(head); 
    return 0;
}

int remove_every_even(node * & head)
{
    if(!head)
        return 0;

    int count = 0;

    if(head -> data % 2 == 0)
    {
        node * temp = head -> next;
        ++count;
        delete head;
        head = temp;
        count += remove_every_even(head);
    }
    else
        count += remove_every_even(head -> next);

    return count;
}


int remove_last_node(node * & head)
{
    if(!head -> next)
    {
        node * temp = head -> next;
        delete head;
        head = temp;
        return 0;
    }
    return remove_last_node(head -> next);
}
