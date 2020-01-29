#include "cs163_entry.h"

//In Lab #4 we will be working with the journal class from Lab #2 and 3. In this lab we will
//extend it by creating a hash table of journals. The data structure will be an array
//of head pointers to linear linked lists of nodes. Each node has a single journal entry

struct node
{
       journal_entry entry; //just one journal entry
       node * next;
};

//Now let's create a table ADT. A table ADT works by the value of the data
//instead of the position of where it is located. It allows us the class designers
//to begin using non-linear data structures!


class table
{
      public:
            /* Implement these three functions for this lab */ 
             table(int size=5);     // IMPLEMENT THIS
             int insert(char * key_value, const journal_entry & to_add);   //IMPLEMENT THIS
             int retrieve(char * title_to_find, journal_entry & found) const;   //IMPLEMENT THIS
  
            int hash_function(char *key) const;
            /* These functions are ALREADY implemented for you */
             ~table(void);    // Already implemented in methods.o   
             int display_all(void) const; /*This is already implemented */
      private:
              node ** hash_table;  //a dynamically allocated array of head pointers
	          int hash_table_size;
              
};
