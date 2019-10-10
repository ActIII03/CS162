//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Program: Food Cart ADT

#include "assign1.h"

int main()
{
    FoodCartList cart_list;

    int decision = 0;
    bool quit = false;

    menu(decision)
    do
    {
        switch(decision)
        {
            case 1:
                cart_list.add_cart();
                break;
            /*case 2:
                cart_list.display_by_type();
                break;
            case 3:
                cart_list.delete_fav_food();
                break;
            case 4:
                cart_list.add_fav_food();
                break; */
            case 5:
                cart_list.display();
                break;
            case 6:
                quit = true;
                break;
        }
        if(quit == false)
            menu(decision);
    }
    while(!quit);

    return 0;
}

