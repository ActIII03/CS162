#include "employee.h"

//Now let's work on the data structure within 
//a hierarchy


//The node is derived from the data and adds
//on the left and right child pointers. 
//THIS HAS ALREADY BEEN COMPLETELY IMPLEMENTED

namespace collection
{
class node: public hourly_employee   
{
      public:
             node();
             node(const hourly_employee &);
             node(const node &);
             void set_left(node * left);
             void set_right(node * right);
             node * & go_left() ;
             node * & go_right() ;
             bool if_left() const;
             bool if_right()const;
      protected:
             node * left;
             node * right;
};



/* The node functions have all been implemented, so you can use them 
   Remember that a "node" IS A "hourly employee", so through the root 
   pointer you can always call all of the public functions within the 
   hourly_employee class and the rest of the hierarchy */

class binary_tree
{
      public:
             binary_tree();     
	     binary_tree(const binary_tree & source);
             ~binary_tree();    
             void display_all();  
      protected:
             //Here are the recursive functions that the public functions call
             void copy_tree(node * & result, node * source);  
             void delete_all(node * & root);                  

             void display_all(node * root); 
             node * root;     //for a tree of hourly employees 
};

class BST: public binary_tree
{
      public:
             BST();     
             bool add(const hourly_employee & to_add); 
      protected:
             //Recursive solution
             bool add(node * & root, const hourly_employee & to_add);  
             int balance_facter;
};

//A store "is a" BST plus more!
class store: public BST
{
      public:
         store();	                       
         store(char * store_name, address & stores_location); 
         void add(const hourly_employee &);
         void display_all();
      protected:
         name store_name;
	     address location;
};
}
