//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include <iostream>
#include "stack.h"

const int MAX_CARDS = 10;
const int MAX_BUFFER = 25;

struct answers
{
    char answer[MAX_BUFFER];

}

struct node
{

    node();
    ~node();
    node * next;
    int top_index;
    stack * stk_card;
}

class trivial_pursuit
{
    public:

        trivial_pursuit();
        ~trivial_pursuit();
        int get_char(answers & player_ans);
        int get_menu_choice(int & choice);

    private:
        
        node * head;
};

