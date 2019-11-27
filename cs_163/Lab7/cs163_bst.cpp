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
    /* Alternative code:
     int count = 0;
     if(!root->left && !root->right){
        counter += 1;
    }

    counter += count(root->left);
    count += count(root->rigt);
    return counter;
    */


    if(!root)
        return 0;
    int num_of_nodes = 0;
    num_of_nodes += count(root -> left);
    num_of_nodes += count(root -> right);
    return 1 + num_of_nodes;

}


// Start with the wrapper function that calls the recursive function
int table::sum()
{

    // Special Case
    if(!root)
        return -1;

    return sum(root);
}

// Now it is your turn to write the sum function recursively
int table::sum (node * root)
{
    if(!root)
        return 0;
    int sum_of_node = 0;
    sum_of_node += sum(root -> left);
    sum_of_node += sum(root -> right);
    sum_of_node += root -> data;
    return sum_of_node;
}

int table::height()   //simply call the private version of the functions
{
    //Call the recursive function here:
    if(!root)
        return -1;
    return height(root);
}

//Now write this function recursively
int table::height(node * root)
{

     if(!root)
         return 0;

     int left = 0, right = 0;
     left += height(root -> left);
     right += height(root->right);

     return 1 + is_max(left, right);

}       

int table::remove_all()
{
    //Call the recursive function here:
    if(!root)
        return -1;
    return remove_all(root);
}

// Now it is your turn to write the remove_all function recursively
int table::remove_all(node * & root)
{
    if(!root)
        return 0;
    int count = remove_all(root -> left);
    count += remove_all(root -> right);
    delete root;
    ++count;
    root = NULL;
    return count;
}  

int table::copy(const table & to_copy)
{
    //Call the recursive function here:
    if(!to_copy.root)
        return -1;
    return copy(root, to_copy.root);

}

// Now it is your turn to write the copy function recursively
int table::copy(node * & dest_root, node * source_root) 
{
    if(!source_root)
    {
        dest_root = NULL;
        return 0;
    }

    dest_root = new node;
    dest_root -> data = source_root -> data;
    dest_root -> right = NULL;
    dest_root -> left = NULL;

    int count = copy(dest_root -> left, source_root -> left);
    count += 1 + copy(dest_root -> right, source_root -> right);
    return count;

}  

int table::is_max(int a, int b)
{
    if( a > b )
        return a;
    else if( a < b )
        return b;
    else
        return a;
}
        
bool table::is_balanced()
{
    if(!root)
        return false;

    if(is_balanced(root) > 0)
        return true;
    else
        return false;

}

int table::is_balanced(node * root)
{
    if(!root)
     return 0;

    int left = 0, right = 0;
    left += height(root -> left);
    right += height(root->right);

    //If height differ by more than one 
    if(abs(left - right) > 1)
        return -1;
    //Otherwise
    else
        return 1 + is_max(left, right);
}
