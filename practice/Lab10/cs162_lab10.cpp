#include "cs162_list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display_all(head);
    
    int new_data = 99;

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    display_first_and_last(head);
    insert_before_last(head, new_data);
    remove_first_two(head);
    display_all(head);
    
    return 0;
}
