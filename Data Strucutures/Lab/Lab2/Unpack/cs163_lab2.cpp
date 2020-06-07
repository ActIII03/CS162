#include "cs163_list.h"
using namespace std;

const int SIZE=100;

int main()
{
    
    char title[SIZE], notes[SIZE];      //temporary for journals
    journal_entry entry, copy_of;                //Start creating entries!
    list my_journal;
    

    //Main has already been written for you to test out
    //the add and find functions
    //
    //Notice how we use the returned value of the functions!
    //Also notice that all communication with the user is
    //done through main (not the ADT)
   

    //Let's create some journal entries
    do
    {
       cout <<"Please enter the title of your journal entry\n";
       cin.get(title, SIZE, '\n'); cin.ignore(SIZE,'\n');
       cout <<"Please enter your notes\n";
       cin.get(notes, SIZE, '\n'); cin.ignore(SIZE,'\n');
        
       entry.create_entry(title, notes);
       bool result = copy_of.copy_entry(entry);
       if(result)
           cout << "Successful copy!" << endl;
       else
           cout << "Unsuccessful copy!" << endl;

       //Now create the journal entry
       /*
       if (entry.create_entry(title, notes)) 
           //if this was successful, let's add it to the list!
          if (! my_journal.add(entry))
              cerr << "We were unable to add it to the list...\n";
        */
     } while (again());
     
     //Now display all that we have
     cout <<"\n\nThe entire list contains the following:\n";
     if (!my_journal.display())
            cerr << "The list is empty...try again\n";


     //The following code demonstrates how to call the find function.
     //You may use this code or modify it to fully test your lab code!
/*

     //Is there an entry we would like to find (by title)?
     cout <<"Enter a title which you would like to find in your journal: ";
     cin.get(title, SIZE, '\n'); cin.ignore(SIZE,'\n');
     if (my_journal.find(title, entry))
     {
        cout <<"\n\nWe found:\n"; 
        if (!entry.display())
            cerr << "Sorry, can't display it at this time\n";
     }
     else  cout <<"\n\nNo match found.\n";
*/
     return 0;
     
}
