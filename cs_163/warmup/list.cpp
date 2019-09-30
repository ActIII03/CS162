//Implementation goes here
#include "helloworld.h"

void hello_world(){

    cout << "Hello World\n";
}

void create_lll(node * & head, node * & tail){

    //Variables
    node * temp;
    node * n_node;
    srand(time(NULL))  // Get different random number
    int arr_size = (rand() % 15 + 1), index = 0;

        
    n_node = new node;
    n_node -> data = (rand() % 100 + 1);
    n_node -> next = NULL;
    head = n_node;
    temp = n_node;

    do{
        ++index;
        n_node = new n_node;
        n_node -> data = (rand() % 100 + 1);
        temp -> next = n_node;
        temp = n_node
    }
    while( index < arr_size);

    temp -> next = NULL;
}




