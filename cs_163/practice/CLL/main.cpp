#include "clist.h"
using namespace std;

int main()
{
    node * rear = NULL;
    build(rear);
    display(rear);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int count = 0;

    count = count_nodes(rear);
    cout << "Number of items in the CLL: " << count << endl;

    display(rear); //resulting list after your function call!
    destroy(rear);
    
    return 0;
}

int count_nodes(node * & rear)
{

    node * current = rear->next;
    int count = 0;
    
    if(rear)
        ++count;

    while(current != rear)
        current = current->next;
        ++count;

    return count;

}
