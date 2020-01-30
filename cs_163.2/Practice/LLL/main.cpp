#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    node * dest = NULL;
    build(head);
    display(head);

    int count = remove_every_even(head);
    cout << "Number of even items removed: " << count << endl;

    display(head);
    destroy(head); 
    return 0;
}

int remove_every_even(node * & head)
{
    if(!head)
        return 0;

    int count = remove_every_even(head -> next);

    if(head -> data % 2 == 0)
    {
        node * temp = head -> next;
        ++count;
        if(!temp)
            return 1;
        delete head;
        head = temp;
    }

    return count;
}
