//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Program: Food Cart ADT

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>

using namespace std;

const int BUFFER_SIZE = 250;

//Dummy variables
struct d_address
{

    char  line_1[BUFFER_SIZE];
    char  location[BUFFER_SIZE];
};

//Dummy Variables
struct d_favorite_three
{
    char  f_1[BUFFER_SIZE];
    char  f_2[BUFFER_SIZE];
    char  f_3[BUFFER_SIZE];
};

//Dummy Variables
struct d_food_cart
{

    char  name[BUFFER_SIZE];
    d_address c_address;
    char  review[BUFFER_SIZE];
    char  type[BUFFER_SIZE];
    d_favorite_three fav_food;
};

//Hold address information
struct address
{

    address();
    ~address();
    char * line_1;
    char * location;
};

//Hold Favorite food items
struct favorite_three
{
    favorite_three();
    ~favorite_three();
    char * f_1;
    char * f_2;
    char * f_3;
};

//Main struct that holds Food Cart Entries
struct food_cart
{

    food_cart();
    ~food_cart();
    char * name;
    address c_address;
    char * review;
    char * type;
    favorite_three fav_food;
};

//LLL node
struct node{

    food_cart fd_cart;
    node * next;
};

int get_char(d_food_cart & new_cart, int menu_choice); //Read inputs from user
void greeting();  //Greet user
void menu(int & decision); //Menu interface module

//Food Cart Object
class FoodCartList
{

    public:

        FoodCartList(void); //Constructor
        ~FoodCartList(void); //Destructor
        int add_cart(const d_food_cart & add_cart); //Add FC to LLL
        int add_fav_food(const d_food_cart & add_cart); // Add Fav Food to emtpy entry hold
        int display_by_type(const d_food_cart & add_cart); //Display FC by type
        int delete_fav_food(const d_food_cart & delete_fav); //Delete Fav Food
        int delete_cart(const d_food_cart & delete_cart); //Delete a Food Cart
        void destroy(node * & head); //Destructor Help function 
        int display();  //Display entries

    private:

        int count(node * head); //Get number of entries
        node * head;
        node * tail;
};
