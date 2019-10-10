//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Program: Food Cart ADT

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int BUFFER_SIZE = 250;

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

void get_char(char * & input_buffer);
void greeting();
void menu(int & decision);

class FoodCartList
{

    public:

        FoodCart();
        ~FoodCart();
        int add_cart();
        int add_fav_food();
        int display_by_type();
        int delete_fav_food();
        int destroy(node * & head);
        int display();

    private:

        node * head;
        node * tail;
};
