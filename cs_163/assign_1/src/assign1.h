//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Program: Food Cart ADT

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct address
{

    char * address_line_1;
    char * address_city;
    char * address_state;
    int address_zip_code;
};

struct food_cart
{

    char * cart_name;
    address cart_address;
    char * cart_type;
    char * cart_food_favorite;
}

struct node{

    food_cart new_cart;
    node * next;
}

class FoodCart
{

    public:

        FoodCart();
        ~FoodCart();


    private:

        node * head;
        node * tail;
};
