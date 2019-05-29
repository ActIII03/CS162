//Name: Armant Touche
//Class: CS162
//Instructor: Jeffery Lund
//Program: This program is called PDX outdoor Activites which will allow user to enter activities and search/display previously created activites
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
 
void greetings();
int menu(int & decision);
bool are_you_sure();

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

struct node
{
    activity_type new_act;
    node * next;
};

class list 
{
    public:
        void read_in();
        void insert(node * current);
        void display();
        void search();
        list();
        ~list();

    private:
        node *head;
};
