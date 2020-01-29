#include "cs163_entry.h"


//Step #7: Implement this function
//This function takes the argument and copies it into
//the journal's data members
int journal_entry::copy_entry(const journal_entry & copy_from)
{
    
        if(copy_from.title)
        {
            title = new char[strlen(copy_from.title) + 1];
            strcpy(title, copy_from.title);
            notes = new char[strlen(copy_from.notes) + 1];
            strcpy(notes, copy_from.notes);
            return true;
        }
        
        return false;
}


//Step #8: Implement this function
//This function will return non-zero if the title sent
//in as an argument matches the data member. It supplies
//the matching journal back as an argument
int journal_entry::retrieve(char * matching_title, journal_entry & found)
{

        if(strcmp(matching_title, title) == 0)
        {
            found.title = new char[strlen(title) + 1];
            strcpy(found.title, title);
            found.notes = new char[strlen(notes) + 1];
            strcpy(found.notes, notes);
            return 0;
        }
        else
            return 1;
}
