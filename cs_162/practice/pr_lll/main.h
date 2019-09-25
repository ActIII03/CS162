#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node{
    int data;
    node * next;
};

void build(node * & head, node * & tail);
void display( node * head);

//My functions
int sum_nodes(node * head);
void swap_first_last(node * & head);
void remove_even_num(node * & head);
bool is_last_odd(node * head);
//bool is_palindrome(int & num_arr[], int begin, int end);
void backward_LLL(node * head);
int num_even_rec(node * head);
void sum_rec( node * head, int & sum);
void display_last_two(node * head);
//void get_int();
void swap_first_last(node * & head);
void move_first_last(node * & head);

void destory(node * & head);
