#include "list.h"

//Place your name here in comments:
//
//
//
int main()
{
    //DO NOT DELETE ANY CODE! Comment it out if you change your mind
    node * head = NULL;
    build(head);
    display_all(head);
    int count = 0;

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    cout << "Number of nodes: " << count_nodes(head) << endl;
   /* cout << "Number of even data: " << count_even(head) << endl;
    //display_last_node(head);
    count = count_nodes(head);
    //display_middle_node(head, count);
    //is_last_node_odd(head, count);
    display_last_two(head, count);
    display_every_other(head);
    //display_all(head);*/;
    destroy(head);    
    swap_first_last(head);

    return 0;
}
