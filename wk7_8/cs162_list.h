//Name: Armant Touche
//Class: CS162
//Instructor: Jeffery Lund
//Program: This program is called PDX outdoor Activites which will allow user to enter activities and search/display previously created activites
#include <iostream>
#include <cstring>

void greetings();
bool are_you_sure();

struct activity_type
{
    char *name;
    char *type;
    char *location;
    int *leng_time;
};

struct node
{
    activity_type new_act;
    node * next;
};

class outdoor_activity
{
    public:
        list();
//        void read_in();

//        ~destructor();
    private:
        int num_of_activities;
        int size;
        node * head;
};
