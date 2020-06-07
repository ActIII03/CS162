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
int remove_every_other(node * & head);
int copy_arr_to_LLL(node * & head);
int copy_arr_to_LLL(node * & head, int arr[], int & index);
int traverse(node * & head, int arr[], int & index);
