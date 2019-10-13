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
    char * city;
    char * state;
    int * zip_code;
};

struct food_cart
{

    char * name;
    address c_address;
    char * type;
    char * cart_food_favorite;
};

struct node{

    food_cart fd_cart;
    node * next;
};

int get_char(food_cart & new_cart);
//void get_int();
void greeting();
void menu(int & decision);

class FoodCartList
{

    public:

<<<<<<< HEAD
        FoodCartList(void);
        ~FoodCartList(void);
        int add_cart();
=======
        FoodCartList();
        ~FoodCartList();
        int add_cart(const food_cart & add_cart);
>>>>>>> b128fd13723260aa6a54c688553eb1a92aa3cc09
        int add_fav_food();
        int display_by_type(); 
        int delete_fav_food(); 
        void destroy(node * & head);
        int display();

    private:

        int count(node * head); 
        node * head;
        node * tail;
};
