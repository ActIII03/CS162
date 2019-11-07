//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "stack_and_queue.h"

using namespace std;

const int BUFFER = 600;


class trivial_pursuit
{
    public:

        trivial_pursuit();
        ~trivial_pursuit();
        int get_txt(char q_1[], char q_2[], char q_3[], char a_1[], char a_2[], char a_3[]);
        int get_answer();
        bool is_correct(char * answer);
        int compare_answer(char * answer);

    private:
        
        //Update constructor
        stack new_q_a;
        stack player_stack; 
        stack discard_stack;
};
