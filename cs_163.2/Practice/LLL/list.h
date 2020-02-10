//list.h
#include <iostream>
#include <cstring>
#include <cctype>

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
int count_LLL(node * head);
int remove_every_even(node * & head);
int remove_last_node(node * & head);
int remove_after_two(node * & head);
int copy_even_to_LLL(node * & head, node * & dest);
int copy_unique_into_array(node * & head);
int copy_unique_into_array(node * & head, int num_arr[], int & index);
bool compare(node * head);
int remove_first(node * & head);
int place_last(node * & head, int first_int);
