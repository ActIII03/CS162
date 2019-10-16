//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Program: Food Cart and I the Asbract Data Type will be LLL

#include "assign1.h"

//
int main(void)
{
    //
    FoodCartList cart_list; //Food Cart Object
    d_food_cart cart_info; //Struct Variable for dummy variables

    int decision = 0;
    bool quit = false;

    //Menu Interface
    greeting();
    menu(decision);

    do
    {
        switch(decision)
        {
            //Add Cart to beginning of the LLL
            case 1:
                get_char(cart_info, decision);
                cart_list.add_cart(cart_info);
                break;

            //Display Food Cart by Food Type
            case 2:
                get_char(cart_info, decision);
                cart_list.display_by_type(cart_info);
                break;

            //Delete Favorite Food
            case 3:
                get_char(cart_info, decision);
                cart_list.delete_fav_food(cart_info);
                break;


            //Add Favorite Food
            case 4:
                get_char(cart_info, decision);
                cart_list.add_fav_food(cart_info);
                break; 

            //Display All Food Cart Entries
            case 5:
                cart_list.display();
                break;
            
            //Quit Program
            case 6:
                quit = true;
                break;

        }
        if(quit == false) //Call Menu Interface again
            menu(decision);
    }
    while(!quit);

    return 0;
}

