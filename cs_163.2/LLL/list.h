#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

struct node
{
    int data;
    node * next;
};

/* These functions are already written and can be called to test out your code */
void build(node * & head);  //supplied
void display(node * head);  //supplied
void destroy(node * &head); //supplied

/* *****************YOUR TURN! ******************************** */
int sum_data(node * head, int & sum);
int copy_into_array(node * head);
int copy_into_array(node * head, int int_arr[], int & index);
int count_nodes(node * head);
int is_greater_than_four(node * head);
int remove_last_two(node * & head);
int remove_every_two(node * & head, node * & previous, int & count);
