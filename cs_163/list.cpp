//Implementation goes here
#include "helloworld.h"

void hello_world(){

    cout << "Hello World\n";
}

void create_lll(node * & head, node * & tail){

    node * temp;
    node * n_node;

    n_node = new node;
    n_node -> data = 5;
    n_node -> next = NULL;
    head = n_node;
    tail = n_node;

    cout << "Data: " << n_node -> data << "\nHead pointer: " << head << "\nTail: " << tail << endl;
}


