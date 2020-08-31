//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;	//some questions are a char * data;
    node * next;
};

class list
{
   public:
   		//These functions are already written
   		list();			//supplied
   		~list();		//supplied
   		void build();	//supplied
   		void display();	//supplied

	/* *****************YOUR TURN! ********************* */
	//Write your function prototype here:
    bool remove_rear_dupl();
    int copy_even(list &);
    int delete_before_even();
    int add_before_even();


	private:
		node * rear;

        bool remove_rear_dupl(node *& current, node *& previous, node * rear, int rear_data);
        int copy_even(node * source_curr, node * source_rear, node *& dest);
        int delete_before_even(node *& current, node *& previous, node *& rear);
        int add_before_even(node *& current, node *& previous, node *& rear);

};
