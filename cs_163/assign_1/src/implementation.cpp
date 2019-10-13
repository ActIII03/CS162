//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Program: Food Cart ADT

#include "assign1.h"

void menu(int & decision)
{
    cout << "Which of the option would like to choose?:\n"
         << "(1) Add Food Cart w/ Favorite Food \n(2) Display Food Cart(s) by Food Type \n(3) Delete Favorite Food from Exisiting Cart \n"
         << "(4) Add Favorite Food to an Existing Cart \n(5) Display Food Cart(s) \n(6) Quit Program \nChoice(1-6):";
    cin >> decision;
    cin.ignore();
    cin.clear();
}

void greeting()
{
    //Stub
}

int get_char(food_cart & new_cart, int menu_choice)
{
    char buffer[BUFFER_SIZE];

    if(menu_choice == 1)
    {
        //Cart Name
        cout << "Please enter the cart's name: ";
        cin.get(buffer, BUFFER_SIZE); 
        cin.ignore();
        cin.clear();
        new_cart.name = new char[strlen(buffer)+1];
        strcpy(new_cart.name, buffer);

        //Address Line 1
        cout << "Please enter the cart's address(Example -- 1234 NE John Jones DR): ";
        cin.get(buffer, BUFFER_SIZE); 
        cin.ignore();
        cin.clear();
        new_cart.c_address.line_1 = new char[strlen(buffer)+1];
        strcpy(new_cart.c_address.line_1, buffer);

        //Location
        cout << "Please enter the cart's Location (Example -- Park Avenuce OR 4th Avenue): ";
        cin.get(buffer, BUFFER_SIZE); 
        cin.ignore();
        cin.clear();
        new_cart.c_address.location = new char[strlen(buffer)+1];
        strcpy(new_cart.c_address.location, buffer);
        
        //Food Type
        cout << "Please enter the cart's food type (Example -- Thai): ";
        cin.get(buffer, BUFFER_SIZE); 
        cin.ignore();
        cin.clear();
        new_cart.type = new char[strlen(buffer)+1];
        strcpy(new_cart.type, buffer);

        //Favorite Food
        cout << "Please enter the cart's favorite food (Example -- Chicken Pad Thai): " ;
        cin.get(buffer, BUFFER_SIZE); 
        cin.ignore();
        cin.clear();
        new_cart.fav_food = new char[strlen(buffer)+1];
        strcpy(new_cart.fav_food, buffer);
        cout << "\n";
    }


    else if(menu_choice == 2)
    {
        //Food Type
        cout << "Please enter a food type you want to see (Example -- Thai): " ;
        cin.get(buffer, BUFFER_SIZE); 
        cin.ignore();
        cin.clear();
        new_cart.type = new char[strlen(buffer)+1];
        strcpy(new_cart.type, buffer);
        cout << "\n";

    }
    

    else if(menu_choice == 3)
    {

        //Delete Favorite Food
        cout << "Please enter the Food Cart you want to delete your favorite food from (Example: Stack High Sandwiches): ";
        cin.get(buffer, BUFFER_SIZE);
        cin.ignore();
        cin.clear();
        new_cart.name = new char[strlen(buffer)+1];
        strcpy(new_cart.name, buffer);
        
        cout << "Please enter your favorite food item you want to delete (Example: California Steak Burrito): ";
        cin.get(buffer, BUFFER_SIZE);
        cin.ignore();
        cin.clear();
        new_cart.fav_food = new char[strlen(buffer)+1];
        strcpy(new_cart.fav_food, buffer);
    }


    else if(menu_choice == 4)
    {

        cout << "Please enter the Food Cart you want to add your favorite food too (Example: Stack High Sandwiches): ";
        cin.get(buffer, BUFFER_SIZE);
        cin.ignore();
        cin.clear();
        new_cart.name = new char[strlen(buffer)+1];
        strcpy(new_cart.name, buffer);
        
        cout << "Please enter your favorite food item you want to add to an existing food cart (Example: California Steak Burrito): ";
        cin.get(buffer, BUFFER_SIZE);
        cin.ignore();
        cin.clear();
        new_cart.fav_food = new char[strlen(buffer)+1];
        strcpy(new_cart.fav_food, buffer);
    }
    
    return 0;

}

FoodCartList::FoodCartList()
{
    head = NULL;
    tail = NULL;

}

FoodCartList::~FoodCartList()
{
    if(head)
    {
        destroy(head);
    }

}

int FoodCartList::add_cart(const food_cart & add_cart)
{

    cout << "Name: " << add_cart.name << endl;
    if(!head){

        node * n_cart = new node;
        head = n_cart;
        head -> next = NULL;
        
        //Name
        n_cart -> fd_cart.name = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.name, add_cart.name);  
        
        //Line 1
        n_cart -> fd_cart.c_address.line_1 = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.c_address.line_1, add_cart.name);  

        //Location
        n_cart -> fd_cart.c_address.location = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.c_address.location, add_cart.name);  
        //Food type
        n_cart -> fd_cart.type = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.name, add_cart.name);  

        //Favorite Food
        n_cart -> fd_cart.fav_food = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.fav_food, add_cart.name);  
    }

    //One Item
    else if(head -> next == NULL)
    {
        
        node * n_cart = new node;
        head -> next = n_cart;
        n_cart -> next = NULL;
        tail = n_cart;
        
        //Name
        n_cart -> fd_cart.name = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.name, add_cart.name);  
        
        //Line 1
        n_cart -> fd_cart.c_address.line_1 = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.c_address.line_1, add_cart.name);  

        //Location
        n_cart -> fd_cart.c_address.location = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.c_address.location, add_cart.name);  
        //Food type
        n_cart -> fd_cart.type = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.name, add_cart.name);  

        //Favorite Food
        n_cart -> fd_cart.fav_food = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.fav_food, add_cart.name);  
    }

    //Insert at the end
    else
    {

        node * n_cart = new node; 
        tail -> next = n_cart;
        tail = n_cart;
        n_cart -> next = NULL;

        
         //Name
        n_cart -> fd_cart.name = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.name, add_cart.name);  
        
        //Line 1
        n_cart -> fd_cart.c_address.line_1 = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.c_address.line_1, add_cart.name);  

        //Location
        n_cart -> fd_cart.c_address.location = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.c_address.location, add_cart.name);  
        //Food type
        n_cart -> fd_cart.type = new char[strlen(add_cart.name)+1];
        strcpy(n_cart -> fd_cart.name, add_cart.name);  

        //Favorite Food
        n_cart -> fd_cart.fav_food = new char[strlen(add_cart.name)+1];
               
    }

    return 0;
}


int FoodCartList::add_fav_food()
{
        //Stub
        return 0;
}

int FoodCartList::count(node * head) 
{
    int count = 0;

    if(!head)
    {
        cout << "Number of Entries: " << count;
        return count;
    }
    else
    {
        while(!head)
        {
            ++count;
            head = head->next;
        }
        cout << "Number of Entries: " << count;
        return count;
    }
}


int FoodCartList::display_by_type(food_cart & display_type)
{
    //Stub  
    if(!head)
        return 0;
    else {
        
}

int FoodCartList::delete_fav_food(food_cart & delete_fav)
{
    //Stub
    return 0;
}

void FoodCartList::destroy(node * & head)
{
    if(!head)
        return;
    else
    {
        node * temp = head -> next;
        delete head;
        head = NULL;
        destroy(temp);
    }
    return;
}

int FoodCartList::display()
{
    if(!head)
    {
        cout << "NO ENTRIES\n";
        return 1;
    }
    else
    {
       while(!head)
        {
            //Look up how to redesign this function
            cout << "Name: " << head->fd_cart.name << endl;
            head = head->next;
        }
        
       return 0;
    }
}
