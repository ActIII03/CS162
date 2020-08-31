#include "supplied.h"
/* This file contains the definition of the node
 * class, as well as its descendents.
 *
 * Author: Mel Flygare <mflygare@pdx.edu>
 * */

// This class represents a node for use by an
// inner object. Inherit from this to create 
// a new node type, such as a node for a 2-3-4
// tree. Only contains data, pointers and
// constructor/destructor.
class node 
{
    public:
        node(int add_val);
        ~node() {  }

        unsigned long data;
};

class LL_node : public node
{
    public:
        LL_node(int add_val);
        ~LL_node();

        LL_node* next;
};

class BST_node : public node
{
    public:
        BST_node(int add_val);
        ~BST_node();
        
        BST_node * left;
        BST_node * right;
};

