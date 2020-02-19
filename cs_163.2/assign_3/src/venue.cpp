//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: 

#include "venue.h"

Venue::Venue()
{
    meal = NULL;
    name = NULL;
    price = 0;
    rating = 0;
    review = NULL;
    category = NULL;
}

Venue::~Venue()
{
    if(meal)
        delete meal;
    if(name)
        delete name;
    if(review)
        delete review;
    if(category)
        delete category;
}

int Venue::get_venue(a_venue & new_venue)
{
    meal = new char[strlen(new_venue.meal) + 1];
    strcpy(meal, new_venue.meal);
    name = new char[strlen(new_venue.name) + 1];
    strcpy(name, new_venue.name);
    price = new_venue.price;
    rating = new_venue.rating;
    review = new char[strlen(new_venue.review) + 1];
    strcpy(review, new_venue.review);
    category = new char[strlen(new_venue.category) + 1];
    strcpy(category, new_venue.category);
    return 0;
}

bool Venue::copy_venue(Venue & add_venue)
{
    if(!add_venue.meal)
        return false;
    meal = new char[strlen(add_venue.meal) + 1];
    strcpy(meal, add_venue.meal);
    name = new char[strlen(add_venue.name) + 1];
    strcpy(name, add_venue.name);
    price = add_venue.price;
    rating = add_venue.rating;
    review = new char[strlen(add_venue.review) + 1];
    strcpy(review, add_venue.review);
    category = new char[strlen(add_venue.category) + 1];
    strcpy(category, add_venue.category);
    return true;
}

void Venue::display()
{

}

int menu()
{
    cout << "\nPlease choose from the following menu options:\n"
         << "(1) Add meal\n(2) Remove an entry by meal\n(3) Remove all entries based on venue(food cart) name\n"
         << "(4) Retireve by meal\n(5) Display all matching the meal\n(6) Quit\nChoice: ";
    int choice = 0;
    cin >> choice;
    cin.ignore(100, '\n');
    return choice;
}
