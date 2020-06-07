#include "cs163_clist.h"
using namespace std;

int main()
{
    node * head = NULL;
    node * copy = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned


    display(head); //resulting list after your function call!


/*
    //If your question needs a second copy of the list, 
    //you can make one by calling the duplicate function:
    cout <<"Here is a duplicate list: ";
    duplicate(copy);
    display(copy);
*/
    
    return 0;
}
