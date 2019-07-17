#include "main.h"

int main(){

    node * head = NULL;
    node * tail = NULL;

    build(head, tail);
    display(head);

    //My functions
    //sum_nodes(head);
    //swap_first_last(head);
    //remove_even_num(head);
    //cout << "Number of nodes: " << count(head) << endl;
    //cout << "Odd?: " << boolalpha << is_last_odd(head) << endl;
    //backward_LLL(head);
    //cout << "Number of even #'s(Recursion): " << num_even_rec(head) << endl;
    //sum_rec(head, sum);
    //cout << "Sum (Recursion): " << sum << endl;
    //2nd display
    //display_last_two(head);
    //swap_first_last(head);
    move_first_last(head);


    display(head);

    //Release memory
    destory(head);

    return 0;
}
