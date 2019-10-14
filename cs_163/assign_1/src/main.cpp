//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Program: Food Cart ADT

#include "assign1.h"

int main()
{
    FoodCartList cart_list;
    food_cart cart_info;
    int decision = 0;
    bool quit = false;

    menu(decision);
    do
    {
        switch(decision)
        {
            case 1:
                get_char(cart_info, decision);
                cart_list.add_cart(cart_info);
                dest_info(cart_info);
                break;
            case 2:
                get_char(cart_info, decision);
                cart_list.display_by_type(cart_info);
                dest_info(cart_info);
                break;
            case 3:
                get_char(cart_info, decision);
                cart_list.delete_fav_food(cart_info);
                dest_info(cart_info);
                break;
            case 4:
                get_char(cart_info, decision);
                cart_list.add_fav_food(cart_info);
                dest_info(cart_info);
                break; 
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

