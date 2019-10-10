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
    cin.get

