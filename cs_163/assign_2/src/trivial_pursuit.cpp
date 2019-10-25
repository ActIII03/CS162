//Name: Armant
//Class: CS 163
//Instructor: Karla Fant
//Description: 
#include "trivial_pursuit.h"

node::node()
{
   top_index = MAX_CARDS;

   next = NULL;
   stk_card = NULL;

}

node::~node()
{

    if(next)
        next = NULL;

    if(stk_card)
        stk_card = NULL;

}

trivial_pursuit::trivial_pursuit()
{

    head = NULL;

}

trivial_pursuit::trivial_pursuit()
{

    if(head)

        head = NULL;

}

int trivial_pursuit::get_char(answers & player_ans)
{

    //Stub
    
    return 0;
}

int trivial_pursuit::get_menu_choice(int & choice)
{

    //Stub

    return 0;

}

