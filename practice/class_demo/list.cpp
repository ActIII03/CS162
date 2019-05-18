/*My name ...

  Purpose: Manages the implementation of
  the functions that deal with a collection
  of movies. This assumes a movie class has
  already been created that deals with the
  underlying data */

#include "classes_intro.h"

/* //Manage a collection of movies
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

}; */

//default constructor
list::list()
{
   num_shows=0;
   
}

//constructor with an argument
list::list(char nme[], int len, char des[])
{
   shows[0].set(nme,len,des);
   num_shows = 1;
}

//read in a show and add it to the list
void list::input()
{

//MAKE SURE TO ERROR CHECK!!!!
    cout <<"We are working on movie #: " 
         <<num_shows+1 <<endl;
    shows[num_shows].input();
    ++num_shows;
}

//Display the entire list of shows
void list::display()
{
    for (int i = 0; i < num_shows; ++i)
        shows[i].display();
}

void list::add(movie & to_add)
{
   //MAKE SURE THERE IS ROOM IN THE ARRAY...
   
   show[num_shows].copy(to_add);
   ++num_shows;
}
