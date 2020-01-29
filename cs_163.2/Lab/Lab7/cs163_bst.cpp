#include "cs163_bst.h"
using namespace std;


// ***These are sample wrapper functions
table::~table()
{
     remove_all(root); //call the recursive removal_all private function
}

// This is a wrapper function that will call the recursive count function
int table::count()
{
    //Notice how the returned value from the recursive function is used
    return count(root);
}

// Now it is your turn to write the count function recursively
int table::count (node * root)
{

}


// Start with the wrapper function that calls the recursive function
int table::sum()
{
    //Call the recursive function here:

}

// Now it is your turn to write the sum function recursively
int table::sum (node * root)
{

}


int table::height()   //simply call the private version of the functions
{
    //Call the recursive function here:

}

//Now write this function recursively
int table::height (node * root){}       



int table::remove_all()
{
    //Call the recursive function here:

}

// Now it is your turn to write the remove_all function recursively
int table::remove_all(node * & root)
{

}  


int table::copy(const table & to_copy)
{
    //Call the recursive function here:

}

// Now it is your turn to write the copy function recursively
int table::copy(node * & dest_root, node * source_root) 
{


}  

