#include "cs163_tree.h"
using namespace std;



//These are the functions that you will be writing for the BST


void table::display_largest(){}      	//STEP 1
void table::display_largest(node * root) {}

int table::count_root() {}		//STEP 2
int table::count_root(node * root, int match) {}

void table::copy(table & source) {}  	//STEP 3
void table::copy(node * & destination, node * source) {}



//Now for the 2-3-4 Tree		//STEP 4
int table::count_3_data()   //sample wrapper function that return the count
{
      return count_3_data(root234);
}	     
     
int table::count_3_data(node234 * root){}	                    


//STEP 5
int table::height(){}                    //Return the height
int table::height(node234 * root){}                    

//STEP 6
//Copy from the argument into the data members...
int table::copy_234(table & copy_from) {}
int table::copy(node234 * & destination, node234 * source){}      
