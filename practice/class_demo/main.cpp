//on unix
//g++ main.cpp class_intro.cpp



//my name...purpose of the code
//that exists in this file

#include "classes_intro.h"

bool again();

bool again()
{
    char response;
    cout <<"Do want another? ";
    cin >>response;
    cin.ignore(100,'\n');
    if (response == 'y')
       return true;
    return false;
}

int main()
{
   
   list action; //10 action movies
   list horror; //10 horror movies
   list coast; //10 coast movies
   list highlander; //10 shows for highlander
   char name[21];
   int movie_length;
   char sort_descrip[41];
   
   //Set the name, length, description first...
   
   //To use a constructor with an argument
   list drama(name, movie_length, short_descrip);
   
   cout <<"Enter action movies: ";
   do
   {
       action.input();
   } while (again());
   
   //display them all
   action.display();
   
    
    cin.get();
    return 0;

}

   
   
   
   
   