//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;;
};

void build(node * & root);  //supplied
void display(node *  root); //supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
int count(node * root);
int average_even(node * root);
int sum_even(node * root);
int display_lrg(node * root);
int display_ios(node * root);
int check_right(node * root);
int copy_BST(node * source, node * & dest);
int inorder_traversal(node * root);
int traverse_ltree(node * root);
