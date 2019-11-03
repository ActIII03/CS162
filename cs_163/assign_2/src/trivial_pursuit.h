//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include <iostream>
#include <fstream>
#include "stack_and_queue.h"

const int BUFFER = 250;

int get_char(answer & player_ans);
int get_menu_choice(int & choice);

class trivial_pursuit
{
    public:

        trivial_pursuit();
        ~trivial_pursuit();
        int get_txt(char q_1[], char q_2[], char q_3[], char a_1[], char a_2[], char a_3[]);
     
    private:
        
        //Update constructor
        stack new_q_a;
        stack player_stack; 
        stack discard_stack;
};
