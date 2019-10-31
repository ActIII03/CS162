//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include <iostream>
#include <cstdlib>
#include "stack.h"
#include <ifstream>

const int BUFFER = 250;

//Acts as buffer for input and is separate from ADT
struct answer
{
    char answer[BUFFER];

};

struct question
{
   char question[BUFFER];
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
        stack  not_answered;
        stack  wrong;
};

