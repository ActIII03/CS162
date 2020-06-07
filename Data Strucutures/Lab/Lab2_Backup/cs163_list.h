//This file contains information for a collection of journal entries
//All of the functions have been implemented except for those that have
//comments indicating that you need to provide the code. Enjoy!
#include "cs163_entry.h"

struct node
{
       journal_entry entry;
       node * next;
};

class list
{
      public:
             //These functions have ALREADY been implemented:
             list(void);
             ~list(void);

	         //Implement these three functions
             int add(journal_entry & to_add);
             int find(char matching_title[], journal_entry & found);
             int display(void);

	         //Append one list onto the end of another
             //Takes the argument and copies the source and places
             //it at the end of the current list
             int append(list & source);
 
      private:
              node * head;
	          node * tail;
};
             
