//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "stack.h"

const int BUFFER = 250;

//Acts as buffer for input and is separate from ADT
struct question
{
   char question_1[BUFFER];
   char question_2[BUFFER];
   char question_3[BUFFER];
};

struct answer
{
    char answer_1[BUFFER];
    char answer_2[BUFFER];
    char answer_3[BUFFER];

};

int get_char(answer & player_ans);
int get_menu_choice(int & choice);

class trivial_pursuit
{
    public:

        trivial_pursuit();
        ~trivial_pursuit();
        bool readin_txt_file(); //Read in to delimiter
     
    private:
        
        //Update constructor
        stack new_q_a;
        stack player_stack; 
        stack discard_stack;
};

