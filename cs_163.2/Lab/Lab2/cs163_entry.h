#include <cstring>
#include <cctype>
#include <iostream>


//This journal supports a title and notes
//In the real world this would contain a date, 
//author, type of journal entry, and much more!
class journal_entry
{
      public:
             /* These functions have ALREADY been created */
             journal_entry(void);
             ~journal_entry(void);
             int create_entry(char * title, char * notes);
             int display(void);

		
	     //Step #7: Implement this function
	     //This function takes the argument and copies it into
             //the journal's data members
             int copy_entry(const journal_entry & copy_from);

             //Step #8: Implement this function
             //This function will return non-zero if the title sent
             //in as an argument matches the data member. It supplies
             //the matching journal back as an argument 
             int retrieve(char * matching_title, journal_entry & found);
      private:
              char * title;
              char * notes;
};
bool again();
