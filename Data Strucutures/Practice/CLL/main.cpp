#include "clist.h"
using namespace std;

int main()
{
    node * rear = NULL;
    build(rear);
    display(rear);

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int count = remove_all(rear, rear -> next);
    cout << "Number of nodes removed from CLL: " << count << endl;



    display(rear); //resulting list after your function call!
    destroy(rear);
    
    return 0;
}

int count_nodes(node * rear, node * & current)
{
    if(!rear)
        return 0;

    if(current -> next == rear)
        return 1;

    int count = count_nodes(rear, current -> next);
    ++count;
    return count;
}

int remove_even(node * & rear, node * & current)
{
    if(current == rear)
    {
        if(current -> data % 2 == 0)
        {
            rear = rear -> next;
            delete current;
            return 1;
        }
        return 0;
    }

    if(current -> next == rear)
    {
        if(current -> data  % 2 == 0)
        {
            node * temp = current;
            current = current -> next;
            delete temp;
            return 1;
        }
        return 0;
    }

    int count = remove_even(rear, current -> next);

    if(current -> data % 2 == 0)
    {
        node * temp = current;
        current = current -> next;
        delete temp;
        ++count;
    }
    return count;
}

int remove_all(node * & rear, node * & current)
{
    if(current == rear)
    {
        delete rear;
        rear = NULL;
        return 1;
    }

    int count = remove_all(rear, current -> next);

    delete current;
    ++count;

    return count;
}
