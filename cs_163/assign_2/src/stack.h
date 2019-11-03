//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include <cstdlib>
#include "queue.h"

struct node {

    node();
    ~node();
    node * next;
    int top_index;   //Keep index here to track and manage
    int arr_size;
    queue * card_arr;  //Pointer to an array  of queue objects *Flexible Arrays*
};


class stack
{
    public:

        stack();
        ~stack();
        int push(questions & in_question, answers & in_answer);   //UPdate argument with struct q & a to push them
        int pop();
        int peek();
        int is_empty();
        int is_full();

    private:

        node * head;

};
