#include "cs163_entry.h"

//In Lab #3 we will be working with the journal class from Lab #2 (where the code
//is already written, compiled, and object code provided. In this lab we will
//extend it by creating a stack of journals. The data structure will be a 
//linear linked list of arrays of dynamicaly allocated journal entries

//Here is the node structure. Remember, whenever you have a pointer you can
//point to one item or the first of many items
struct node
{
       journal_entry * entries; //a dynamically allocated array of journal entries
       node * next;
};

//Now let's create a stack. Stacks should be able to keep a collection of
//data and push (add at the beginning), pop (remove at the beginning), 
//display all, and peek (retrieve the information at the beginning).

//Create arrays of const size MAX
const int MAX = 5;

class stack
{
      public:
             //These functions have ALREADY been written for you
             stack(void);     
             ~stack(void);     
             int display_all(void) const; 
            
 
             //Peek: You need to get back through the argument list the
             //journal on the top of the stack but don't change the stack
             int peek(journal_entry & top_entry) const; 
             int push(const journal_entry & new_entry);  //to push the argument onto the stack
             int pop (void); 

  
      private:
              node * head;
              int top_index;   //Index is zero 
              
};
             
