//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;   //some questions are a char * data;
    node * next;
};

class list
{
   public:
   //These functions are already written for you
     list();			//supplied
     ~list();			//supplied
     void build();     		//supplied
     void display();  		//supplied
    
    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
    void hello();
    int display_unique();
    int average_unique();
    int remove_duplicate();

   private:		//notice there is both a head and a tail!
      node * head;
      node * tail;

    //Write your function prototype here:
    int display_unique(node * head, node * first_item);
    bool is_unique(node * head, node * first_item, node * searched_item);
    int average_unique(node * head, node * first_item, int & sum);
    int remove_duplicate(node * & head, node * first_item);

};
