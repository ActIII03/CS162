//Name: Armant Touche
//Class: CS162
//Instructor: Jeffery Lund
//Program: This program is called PDX outdoor Activites which will allow user to enter activities and search/display previously created activites
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
 
void greetings();
bool are_you_sure();

struct node
{
    activity_type new_act;
    node * next;
};

class activity_type
{
    public:
        void read_in();
        activity_type();
        ~activity();
    private:
        char *name;
        /*char *type;
        char *location;
        int *leng_time;*/
};

class list 
{
    public:
        void insert(activty_type & to_insert);
        list();
        ~list();

    private:
        int num_of_activities;
        node *head;
};
