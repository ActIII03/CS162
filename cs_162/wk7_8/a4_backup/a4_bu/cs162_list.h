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

struct activity_type
{
    char *name;
/*    char *type;
    char *location;
    int *leng_time;*/
};

struct activity_node
{
    activity_type new_act;
    activity_node * next;
};

class outdoor_activity
{
    public:
        void read_in(activity_type);
        //void add_list();
        outdoor_activity();
        ~outdoor_activity();

    private:
        int num_of_activities;
        activity_node *head;
};
