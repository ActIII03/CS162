//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Program: Food Cart ADT

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstring>

using namespace std;

const int BUFFER_SIZE = 250;

struct address
{

    char * line_1;
    char * location;
};

struct favorite_three
{
    char * f_1;
    char * f_2;
    char * f_3;
};

struct food_cart
{

    char * name;
    address c_address;
    char * review;
    char * type;
    favorite_three fav_food;
};

struct node{

    food_cart fd_cart;
    node * next;
};

void dest_info(food_cart & dest_info);
int get_char(food_cart & new_cart, int menu_choice);
//void get_int();
void greeting();
void menu(int & decision);

class FoodCartList
{

    public:

        FoodCartList(void);
        ~FoodCartList(void);
        int add_cart(const food_cart & add_cart);
        int add_fav_food(const food_cart & add_cart);
        int display_by_type(const food_cart & add_cart); 
        int delete_fav_food(const food_cart & add_cart); 
        void destroy(node * & head);
        int display();

    private:

        int count(node * head); 
        node * head;
        node * tail;
};
