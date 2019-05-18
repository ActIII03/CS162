//My name...purpose of the class

//Header file include:
//#includes
//prototypes
//structs
//class interfaces

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//class interface...put this in a 
//header file!!!!!!
class movie
{
   
   public:   //member functions
      //the default constructor initializes data
      //members
      movie();    //constructor (default)
      movie(char name[], int len, char desc[]);
      void set(char[], int, char[]);
      
      int input();
      int copy(movie &);
      //int change_name(char name[]);
      void display();
      //int compare(char compare_to[]);
      
   private:  //data members and utility functions
      char name[21];
      int length;
      char description[131];
};

//Manage a collection of movies
class list
{
    public:
       list(); //default constructor
       list (char name[], int length, char de[]);
       void add(movie & to_add);
       void input(); //reads in a movie and adds
                     //it to the list of movies
       void display(); //display all...
       //....  
    private:
       movie shows[10];
       int num_shows;

};




