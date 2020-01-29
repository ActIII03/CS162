#include "cs163_table.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the hash table and initialize each
      //element and data member.

}
//Do something with the key being passed 
//in and return a number(or in our case an index)
//Make sure you're within the array size!
int table::hash_function(char *key) const
{
    //Place your code here

}

//Using a hash function, insert a new value into the 
//head of the chain
int table::insert(char * key_value, const journal_entry & to_add)
{

        //Place your code here

}

//Using a hash function determine which chain to search
//then return 0 if no match is found
int table::retrieve(char * title_to_find, journal_entry & found) const
{

        //Place your code here

}

