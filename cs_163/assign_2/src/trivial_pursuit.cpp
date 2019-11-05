//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "trivial_pursuit.h"

trivial_pursuit::trivial_pursuit()
{
    //new_q_a = NULL;
    //player_stack = NULL;
    //discard_stack = NULL;
}

trivial_pursuit::~trivial_pursuit()
{

    //if(new_q_a)
    //    new_q_a = NULL;
    //if(player_stack)
    //    player_stack = NULL;
    //if(discard_stack)
    //    discard_stack = NULL;

}

int get_char(char answer[])
{

    //Stub
    
    return 0;
}

int get_menu_choice(int & choice)
{

    //Stub

    return 0;

}

int trivial_pursuit::get_txt(char q_1[], char a_1[], char q_2[], char a_2[], char q_3[], char a_3[])
{
    new_q_a.push(q_1, a_1, q_2, a_2, q_3, a_3);

    return 0;
}

int trivial_pursuit::get_question()
{
    //Pop card here
    queue * temp = new_q_a.pop();
    //temp -> display();  //Delete temp ptr after display
    return 0;
}
