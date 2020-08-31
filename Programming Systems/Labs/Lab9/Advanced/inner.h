#include "nodes.h"

/* This file contains the definition of the inner
 * class, as well as its descendents.
 *
 * Author: Mel Flygare <mflygare@pdx.edu>
 * */

// This class represents the inner data structure
// of an array of objects. It is an abstract base
// class. Inherit from this to create another inner
// object type.
class Inner
{
    public:
        virtual ~Inner() {  }
        virtual void display_all() = 0;
        virtual unsigned long sum_data() = 0;
        virtual unsigned long max_data() = 0;
        virtual void insert(int to_add) = 0;
};

class LLL : public Inner
{
    public:
        LLL();
        ~LLL();
        virtual void display_all(); // supplied
        virtual void insert(int to_add); // supplied

        // Complete these
        virtual unsigned long sum_data();
        virtual unsigned long max_data();
    private:
        void display_all(LL_node* head); // supplied

        // Complete these
        unsigned long sum_data(LL_node* head);
        unsigned long max_data(LL_node* head);
        
        LL_node* head;
};

class BST : public Inner
{
    public:
        BST();
        ~BST();
        virtual void display_all(); // supplied
        virtual void insert(int to_add); // supplied

        // Complete these
        virtual unsigned long sum_data();
        virtual unsigned long max_data();
    private:
        void insert(BST_node*& root, int to_add); // supplied
        void display_all(BST_node* root); // supplied
        
        // Complete these
        unsigned long sum_data(BST_node* root);
        unsigned long max_data(BST_node* root);

        BST_node* root;
};


