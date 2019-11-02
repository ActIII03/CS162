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
//Write your function prototype here:
int count_first(node * head, int & count);
int count_last(node * head, int & last_node);
int is_bigger_than_four(node * head);
int switch_first_last(node * & head);
int insert_arr_to_LLL(node * & head, const int num_arr[]);
int copy_LLL_to_arr(node * head);
int remove_last_two(node * head);
int remove_every_two(node * & head);
int average_even(node * head);
int sum_data(node * head, int & count);

//Recursion
int count_first_rec(node * head, int & first_node);
int count_last_rec(node * head, int & last_node, int & count);
int is_bigger_than_four_rec(node * head, int & count);
int switch_first_last_rec(node * & head, node * & tail);

