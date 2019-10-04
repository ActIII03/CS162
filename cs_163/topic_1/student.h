
//#include's, prototypes for ADT, structs
//classes
//Dont forget your name!

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


//manages an individual student
class student
{
      public:
            student(); 
            //student(char name[], char id[]);
            //student(const student &);
            ~student();
            int set(student &);
            int set(char name[], char id[]);
            int display();
            int reset_student();
            int change_name( char replacement[]);
            //returns true if id matches
            int compare(char id[], char fnd[]);
            int compare(char id[], student & fnd);
            //give the id for a matching name
            int find(char name[], char id[]);

       private:
              char * name;
              char * id;
              //....and other data members
};

struct node
{
       student peer;
       node * next;
};
            
                             
             
             
             
             
             
             
             
