#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node{
    
    //Variables
    int data;   //<data_type> <var_name>
    node * next;
};

void hello_world();
void create_lll(node * & head, node * & tail);
