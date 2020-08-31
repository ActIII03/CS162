//arr.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;  //some questions are char * data;
    node * next;
};

class table
{
    public:
    /* These functions are already written */
       table();		//supplied
       ~table();	//supplied
       void build();  	//supplied
       void display();  //supplied

    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
    int display_arr();
    int average_even(table & new_arr);
    //mpdemo question - return the most repeated element count if not unique
    int all_unique();

    private:
       node ** head; 	//dynamically allocated array
       int size; 	//the array size

    int display_arr(node ** head, int & index);
    int display(node * head);
    int average_even(node ** source, node ** dest, int & index, float & sum);
    int average_even(node * source, node *& dest, float & sum); 
    //mpdemo question
    int traverse_ARR(node ** head, int & index);
    int traverse_LLL(node * head);
    int traverse_unique(node * head, int search);
};
