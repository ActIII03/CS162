//doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;		//some questions use a char * data;
    node * previous;
    node * next;
};

class list
{
    public:
        //These functions are already written
        list();         //supplied
        ~list();        //supplied
        void build();   //supplied
        void display(); //supplied
        

     /* *****************YOUR TURN! ******************************** */
     /* place your prototype here */
    int remove_larger_than_first();
    int display_reverse();
    int duplicate(list & source);
     
     private:
         node * head;   //notice there is both a head
         node * tail;   //and a tail, common for DLL

    int remove_larger_than_first(node * & head, int first_data);
    int display_reverse(node * current); 
    int duplicate(node * source_curr, node *& dest, node *& dest_prev);
};
