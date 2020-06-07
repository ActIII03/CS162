// Name:   Class:  
// Purpose of the program...
// is to manage an array of movies 
// providing a way to read and display
// using structures and functions

#include <iostream>
#include <fstream>
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

//fill up the array -- lecture #8
//returns success/failure (failure means there 
//was a problem with the external data file
bool load_movies(char filename[], movie[], int & num); 
bool save_movies(char filename[], movie[], int num);
void getfilename(char filename[]);

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

//Ask the user what file they want to work with
void getfilename(char array[])
{
    read("Please enter the name of a file limited to 31 characters: ", 31, array);
    strcat(array,".txt");
}

//manage a collection of movies
void manager(movie array[], int max_num_movies)
{
    char filename[35]; //holds the file name 
    
    int num_movies=0; //the number of movies in the array
    
    
    getfilename(filename);
    if(!load_movies(filename, array, num_movies))
        cout <<"We are starting from scratch! No movies existing\n\n";
        
    int i = num_movies;
    do
    {
         readall(array[i]);
         displayall(array[i]); 
         ++i;    
    } while (more() && i < max_num_movies);
    
    if (!save_movies(filename, array, i))
       cout <<"Problems with your file!\n\n\n";
       
    //Display all movies:
    cout <<"The entire library of movies contains these shows: ";
    for (int j=0; j < i; ++j)
        displayall(array[j]);
        
}
//Load all movies from an external file!
bool load_movies(char filename[], movie movies[], int & num)
{ 
    ifstream read;
    read.open(filename); //connect up
    
    if (!read) //not connected
       return false;
    
    //Connected to the file and ready to read
    read.get(movies[num].title,SIZE_TITLE,'|');
    read.ignore(100,'|');
    while(read && !read.eof()) //previous read is successful
    {
        read.get(movies[num].description,SIZE_DESC,'|');
        read.ignore(100,'|');
        read.get(movies[num].category, SIZE_CAT, '|');
        read.ignore(100,'|');
        read.get(movies[num].rating, SIZE_RATING, '|');
        read.ignore(100,'|');
        read >> movies[num].length;
        read.ignore();
        ++num;
        read.get(movies[num].title,SIZE_TITLE,'|');
        read.ignore(100,'|');
    }
    read.close();
    return true;
}

//Write all of the movies out to a file
bool save_movies(char filename[], movie movies[], int num)
{
    bool success = true;
    ofstream write;
    write.open(filename);  //rewrite over the entire file!
    
    if (!write) //true -- connect; false -- problem
    {
       cout <<"CAN'T SAVE...\n\n";
       success = false;
    }
    else
    {
       for(int i=0; i < num; ++i)
       {
        write << movies[i].title  <<"|"
              << movies[i].description  <<"|"
              << movies[i].category  <<"|"
              << movies[i].rating <<"|"
              << movies[i].length <<endl;
       }
       write.close();
       write.clear();
    }
    return success;
}

//Do you want to enter more?
bool more()
{
    char response;
    cout <<"Would you like to enter another? Y/N ";
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







