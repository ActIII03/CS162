//My name ....
//Comments: purpose of the structs/classes
//that exist in this file

//#include's, prototypes for ADT, structs
//classes

#include <iostream>
#include <cstring>
#include "student.h"
#include <cctype>
using namespace std;
            
//groups students together into a roster
class roster
{
      public:
          roster();
          ~roster();
          //roster(const roster &);
          int add(const student & to_add);
          int add(char name[], char id[]);
          int find(char found_name[], char id_search[]);
          int display_all();
          //int drop(char id[]);
      private:
          node * head;
          //do we  need a node * tail too?
};
                             
             
             
             
             
             
             
             
