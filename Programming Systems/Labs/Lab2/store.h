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



/* THIS IS THE CLASS WHERE YOU WILL BE MAKING CHANGES FOR LAB #2 
   The node functions have all been implemented, so you can use them 
   as you get used to the concept of having a node be a class instead
   of a struct.

   Remember that a "node" IS A "hourly employee", so through the root 
   pointer you can always call all of the public functions within the 
   hourly_employee class and the rest of the hierarchy */

class binary_tree
{
      public:
             binary_tree();     			
			 //Step 5b - Put the Copy Constructor prototype here

             ~binary_tree();    
             void display_all();  
      protected:
             //Here are the recursive functions that the public functions call
             void copy_tree(node * & result, node * source);  
             void delete_all(node * & root);                 

             void display_all(node * root); //Already Implemented
             node * root;                   //a tree of hourly employees 
};

//THE CODE WILL NOT COMPILE UNTIL THIS LINE IS COMPLETED.....
//IN LAB #2 Step 5c - COMPLETE THE DERIVATION LIST:
class BST: public binary_tree
{
      public:
             BST();    

             //No need for copy constructor or destructor
             //since that is handled by the base class
             //and since this class handles no dynamic memory

	         //Hire an hourly worker...already implemented
             bool add(const hourly_employee & to_add);  
      protected:
             //Recursive solution
             bool add(node * & root, const hourly_employee & to_add);  
             int balance_factor;
};

//A store "is a" BST plus more!
class store: public BST
{
      public:
             store();	                       
             store(char * new_store_name, address & stores_location); 
             void add(const hourly_employee &);
             void display_all();
             //void hire_salaried(salaried_employee &);
      protected:
             name store_name;
	         address location;
};
}
