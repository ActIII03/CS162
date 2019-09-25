// Name:   Class:  
// Purpose of the program...
// is to manage an array of movies 
// providing a way to read and display
// using structures and functions

#include <iostream>
using namespace std;
#include <cstring>
#include <cctype>

//Create constants used as array sizes
const int SIZE_TITLE = 131;
const int SIZE_DESC = 300;
const int SIZE_RATING = 6;
const int SIZE_CAT = 16;

//This creates a grouping for an individual show
struct movie
{
    char title[SIZE_TITLE];
    char description[SIZE_DESC];
    char rating[SIZE_RATING];
    char category[SIZE_CAT];
    int length;
};

//Function prototypes
//Read in one array of characters after prompting
void read(char prompt[], int max_size, char result[]);
void readall(movie &); //read all members of the struct
void displayall(movie &); //display all members
void manager(movie [], int); //orchestrate the collection of movies
bool more(); //would the user like more?

int main()
{
    //create the collection of movies
    movie kids[100];
    movie vacation[50];
    movie fun[200];
    
    manager(fun, 200);  //Managing the collection of movies
    //...there may be other jobs that main needs to
    //do for the application program
    
    cin.get();
    return 0;
}

//manage a collection of movies
void manager(movie array[], int max_num_movies)
{
    int i = 0;
    do
    {
         readall(array[i]);
         displayall(array[i]); 
         ++i;    
    } while (more() && i < max_num_movies);
}

//Do you want to enter more?
bool more()
{
    char response;
    cout <<"Would you like to enter another? Y/N";
    cin >>response;
    cin.ignore(100,'\n');
    if (toupper(response) == 'Y')
       return true;
    return false;
}

//Read in one array of characters after prompting
//The first argument is passed in with the information
//that represents the prompt (or what we want to ask
//the user. The second argument represents the maximum
//size to read in. The third argument is where we will
//store the characters read in.
void read(char prompt[], int max_size, char result[])
{
    cout <<prompt;
    cin.get(result, max_size, '\n');
    cin.ignore(100,'\n');
}

//This function reads in every member of the movie
//struct
void readall(movie & a_show)
{
    read("Please enter a title: ",SIZE_TITLE, a_show.title);
    read("Please enter the description: ",
         SIZE_DESC, a_show.description);
    read("Please enter a rating (1-5 *****!): ",
         SIZE_RATING, a_show.rating);
    read("Please enter the category: ", SIZE_CAT, 
         a_show.category);
    cout << "Please enter the length: ";
    cin >> a_show.length;
    cin.ignore(100,'\n');
}

//Display all members of the movie passed in
void displayall(movie & show)
{
    cout <<"\n\n" 
         <<show.title <<'\t' <<show.description <<endl
         <<"Rating: " <<show.rating <<'\t' 
         <<"Category: " <<show.category 
         <<'\t' <<"Length: " <<show.length <<endl;
}







