#include <cstring>
#include <cctype>
#include <iostream>

//This journal entry supports a title and notes
//In the real world this would contain a date, author, 
//type of journal entry, and much more!

#ifndef JOURNAL
#define JOURNAL
class journal_entry
{
      public:
             /* All of these functions have ALREADY been written */
             journal_entry(void);
             ~journal_entry(void);
             int create_entry(char * title, char * notes);
             int copy_entry(const journal_entry & a_new_entry);
             int retrieve(char * title, journal_entry & found) const;   
             int retrieve(journal_entry & found) const;   //added for lab #3!
             int display(void) const;
      private:
              char * title;
              char * notes;
};
#endif
bool again();
