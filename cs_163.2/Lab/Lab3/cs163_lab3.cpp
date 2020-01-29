#include "cs163_stack.h"
#include "cs163_queue.h"

using namespace std;

int main()
{
    /*
    stack my_journal;
    journal_entry to_add, an_entry;
    char title[100];
    char notes[300];
    
    //Let's add some items ot the journal first
    do
    {
       cout <<"Please enter a title: ";
       cin.get(title, 100); cin.ignore(100,'\n');
       cout <<"Please enter the notes: ";
       cin.get(notes, 300); cin.ignore(100,'\n');
       to_add.create_entry(title, notes);
       
       //now push it on the stack
       my_journal.push(to_add);
       
    } while (again());
    
    //Let's display what we have  (this function was provided for you)
    cout <<"\n\nThis is the contents of the stack: ";
    my_journal.display_all();

    
//Now pop!
    do
    {
          
       if(!my_journal.pop()) 
       {
          
          cout <<"\n\nAfter removing this is what we have: ";
          my_journal.display_all(); 
       }
       else  cout <<"\nNothing could be removed, the stack is empty! " <<endl;
    } while (again());

    //Now begin working with the queue portion of the lab. Uncomment out this code when you have reached this part)
    
    do
    {
        if(my_journal.peek(to_add) == 1)
        {
            cout << "After peek!" << endl;
            to_add.display();
        }
        else
            cout << "Nothing to peek at!" << endl;

    }while(again());
    */

    queue my_journal;
    journal_entry to_add, an_entry;
    char title[100];
    char notes[300];

    //Let's add some items ot the journal first
    do
    {
       cout <<"Please enter a title: ";
       cin.get(title, 100); cin.ignore(100,'\n');
       cout <<"Please enter the notes: ";
       cin.get(notes, 300); cin.ignore(100,'\n');
       to_add.create_entry(title, notes);
       
       //now enqueue it onto the queue
       my_journal.enqueue(to_add);
       
    } while (again());
    
    //Let's display what we have  (this function was provided for you)
    cout <<"\n\nThis is the contents of the queue: ";
    my_journal.display_all();

    
//Now dequeue
    do
    {
          
       if( my_journal.dequeue()) 
       {
          
          cout <<"\n\nAfter removing this is what we have: ";
          my_journal.display_all(); 
       }
       else  cout <<"\nNothing could be removed, the queue is empty! " <<endl;
    } while (again());
    
    return 0;
}
