//Name: Armant Touche
//Class: CS162
//Instructor: Jeffery Lund
//Program: This program is called PDX outdoor Activites which will allow user to enter activities and search/display previously created activites
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
 
//Help modules
void greetings();
int menu(int & decision);

//Activity class
class activity_type
{
    public:
        void copy_act(char t_name[], char t_type[], char t_location[], int t_length);
        activity_type();
        ~activity_type();
        char *name;
        char *type;
        char *location;
        int length;
    private:
        int counter;
        
};

//Node struct
struct node
{
    activity_type new_act;
    node * next;
};

//List manager for my LLL
class list 
{
    public:
        void read_in();
        void insert(node * current);
        void display();
        void search();
        void destroy(node * & head);
        list();
        ~list();
    private:
        node *head;
};
