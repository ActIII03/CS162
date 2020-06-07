   //My name ... purpose of code...
   //This file manages the creation and
   //modification of a movie's data
   
   #include "classes_intro.h"   
      
      movie::movie()    //constructor (default)
      {
          name[0] = '\0';
          length = 0;  
          description[0] = '\0';
      }  
      
      //constructor that starts out with data
      //rather than being zero equivalent
      movie::movie(char in_name[], int in_len, char in_desc[])
      {
           strcpy(name, in_name);
           length = in_len;
           strcpy(description, in_desc);
      }
      
      void movie::set(char in_name[], int in_len, char in_desc[])
      {
           strcpy(name, in_name);
           length = in_len;
           strcpy(description, in_desc);
      }
      //Read in the movie information from the user
      int movie::input()
      {
           int success = 1;
           
           cout << "Please enter a movie name: ";
           cin.get(name, 21, '\n');
           cin.ignore(100,'\n');
           if (!cin)
               success = 0;
           else
           {
           
              cout << "Please enter the length of "
                <<name <<": ";
              cin >> length;
              cin.ignore(100,'\n');
           
              cout << "Please enter the description of "
                 <<name <<": ";
              cin.get(description, 131, '\n');
              cin.ignore(100,'\n');
            }
            return success;
      }
      
      //We are copying from the argument and storing
      //it into the data members!!
      int movie::copy(movie & source)
      {
          strcpy(name, source.name);
          length = source.length;
          strcpy(description, source.description);
      }
      
      
      /*
      int change_name(char name[]);*/
      void movie::display()
      {
          cout <<name <<'\t' <<description <<'\t'
               <<"length is: " <<length <<" minutes"
               <<endl;
      }
      
      /*
      int compare(char compare_to[]); */
