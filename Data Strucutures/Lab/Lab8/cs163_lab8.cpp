#include "cs163_graph.h"
using namespace std;

int main()
{
    table my_journal;
    journal_entry to_add, an_entry;
    char title[100], connected[100];
    char notes[300];
    
    //Let's add some items ot the journal first
    do
    {
       cout <<"Please enter a title: ";
       cin.get(title, 100); cin.ignore(100,'\n');
       cout <<"Please enter the notes: ";
       cin.get(notes, 300); cin.ignore(100,'\n');
       to_add.create_entry(title, notes);
       
       //now insert it into the graph
       my_journal.insert_vertex(to_add);
       
    } while (again());
   
    //Let's add some connections
    do
    {
       cout <<"Enter two titles that are related (connected): ";
       cin.get(title, 100); cin.ignore(100,'\n');
       cin.get(connected, 100); cin.ignore(100,'\n');
       my_journal.insert_edge(title, connected);
       my_journal.insert_edge(connected, title); //not a directed graph
    } while (again());
   
    //Display direct connections (call your function)
        
    //Let's display what we have  (this function was provided for you)
    cout <<"\n\nThis is the contents of the table:\n";
    my_journal.display_all();
    
    
    return 0;
}
