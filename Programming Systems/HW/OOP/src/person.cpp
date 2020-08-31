//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Time Managment System
#include "person.h"


person::person()
{
    list_of_days = NULL;
}

person::~person()
{

}   

bool again()
{
    bool again = true;
    char choice;

    cout << "Would you like to keep going (Y/N):";
    cin >> choice;
    cin.ignore(MAX, '\n');

    if(toupper(choice) != 'Y')
        again = false;

    return again;
}


void person::create_day_planner(int length)
{
    
}
