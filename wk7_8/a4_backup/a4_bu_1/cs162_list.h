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

class activity_type
{
    public:
        void read_in(activity_type & temp_act);
        void copy_act(activity_type & to_copy);
        activity_type();
        ~activity_type();
    private:
        char *name;
        /*char *type;
        char *location;
        int *leng_time;
        int counter */
        
};

class list 
{
    public:
        void insert(activty_type & to_add);
        list();
        ~list();

    private:
        node *head;
};

struct node
{
    activity_type new_act;
    node * next;
};
