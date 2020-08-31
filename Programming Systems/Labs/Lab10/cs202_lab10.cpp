#include "table.h"
using namespace std;

//These are the functions that you will be writing for Lab #10


//STEP 1
int table::count()	//SAMPLE wrapper function
{
	return count(root);
}

int table::count(node * root){}


//STEP 2
int table::count_right_subtree(){}
int table::count_right_subtree(node * root){}


//STEP 3
int table::remove_largest(){}
int table::remove_largest(node * & root){}


//STEP 4
int table::sum(){}
int table::sum(node * root){}

//STEP 5
int table::copy(table & to_copy){}
int table::copy(node * & destination, node * source){}


//STEP 6a Challenge
int table::create_full(){}
int table::create_full(node * & new_tree){}


//STEP 6b
bool table::is_full(){}
bool table::is_full(node * root){}


//STEP 6c
int table::display_largest(){}
int table::display_largest(node * root){}


//STEP 6d
int table::display_largest2(){}
int table::display_largest2(node * root){}



