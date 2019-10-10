//Name: Armant Touche
//Class: CS 163 Data Structures
//Instructor: Karla Fant
//Program: Food Cart ADT

#include "assign1.h"

void menu(int & decision)
{
    cout << "\nWhich of the option would like to choose?:\n";
         << "(1) Add Food Cart w/ Favorite Food\n (2) Display Food Cart(s) by Food Type\n (3) Delete Favorite Food from Exisiting Cart\n";
         << "(4) Add Favorite Food to an Existing Cart\n (5) Display Food Cart(s)\n  (6) Quit Program\n";

    cin >> decision;
    cin.ignore;
}

void greeting()
{
    //Stub
}

void get_char(char * & input_buffer);
{
    //istringstream input("Hot Dog Stand\n");

    cin.get(input_buffer, BUFFER_SIZE, "\n");
    cin.ignore(100, "\n");

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

int FoodCart::add_cart()
{
    //Stub
    return 0;
}


int FoodCartList::add_fav_food()
{
    //Stub
    return 0;
}

int FoodCartList::count() 
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
        return 1;
    else
    {
       while(!head)
        {
            cout << "Name: " << head->fd_cart.name << endl;
            head = head->next;
        }
        
       return 0;
    }
}
}

