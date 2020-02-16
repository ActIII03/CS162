//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: 

#include "venue.h"

Venue::Venue()
{
    meal = NULL;
    price = 0;
    rating = 0;
    review = NULL;
    category = NULL;
}

Venue::~Venue()
{
    if(meal)
        delete meal;
    if(review)
        delete review;
    if(category)
        delete category;
}

int Venue::get_venue(a_venue & new_venue)
{

    return 0;
}

int Venue::copy_venue(const a_venue & add_venue)
{
    return 0;
}

void Venue::display()
{

}

int menu()
{
    return 0;
}
