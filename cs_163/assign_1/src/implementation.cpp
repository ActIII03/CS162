//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Program: Food Cart ADT

#include "assign1.h"

void menu(int & decision)
{
    cout << "\nWhich of the option would like to choose?:\n"
         << "(1) Add Food Cart w/ Favorite Food\n (2) Display Food Cart(s) by Food Type\n (3) Delete Favorite Food from Exisiting Cart\n"
         << "(4) Add Favorite Food to an Existing Cart\n (5) Display Food Cart(s)\n  (6) Quit Program" << endl;

    cin >> decision;
    cin.ignore();
}

void greeting()
{
    //Stub
}

int get_char(food_cart & new_cart)
{
    char buffer[BUFFER_SIZE];
    //Cart Name
    cout << "Please enter the cart's name : " << endl;
    cin.get(buffer, BUFFER_SIZE); 
    cin.clear();
    cin.ignore();
    cout << "Buffer: " << buffer << endl;
    new_cart.name = new char[strlen(buffer)+1];
    strcpy(new_cart.name, buffer);
    //
    cout << "Please enter the cart's name : " << endl;
    cin.get(buffer, BUFFER_SIZE); 
    cin.clear();
    cin.ignore();
    cout << "Buffer: " << buffer << endl;
    new_cart.name = new char[strlen(buffer)+1];
    strcpy(new_cart.name, buffer);
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
    //List of entries
    int line_entry = 0;
    cout << "Name: " << add_cart.name << endl;
    /*if(!head){
        node n_cart = new food_cart;
        cout << "Line entry: " << line_entry << endl;
        n_cart.name = new char[strlen(buffer)+1];
        strcpy(n_cart.name, buffer);
        cout << "Name: " << n_cart.name << endl;
    }*/
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


int FoodCartList::display_by_type()
{
    //Stub  
    cout << "Function Call\n";
    return 0;
}

int FoodCartList::delete_fav_food()
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
