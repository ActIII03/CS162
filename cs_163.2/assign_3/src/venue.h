//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: 

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

#ifndef MEALS
#define MEALS

struct a_venue
{
        char meal[30];
        int price;
        int rating;
        char review[100];
        char category[30];
};

class Venue
{
    public:

        //Constructor and Destructor
        Venue();
        ~Venue();

        // Get user's text input
        int get_venue(a_venue & new_venue);

        // Copy information
        int copy_venue(const a_venue & add_venue);

        // Display Venue
        void display();

        char * meal;
        int price;
        int rating;
        char * review;
        char * category;

};
#endif

int menu();
