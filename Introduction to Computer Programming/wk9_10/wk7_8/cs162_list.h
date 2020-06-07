//Name: Armant Touche
//Class: CS162
//Instructor: Jeffery Lund
//Program: PDX Event tracker
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;
 
//Help modules
void greetings();
int menu(int & decision);

//Activity class
class event_type
{
    public:
        void copy_event(char t_name[], char t_month[], int t_day);
        event_type();
        ~event_type();
        char *name;
        char *month;
        int day;
    private:
        int counter;
};

//Node struct
struct node
{
    event_type new_event;
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
        void remove();
        void destroy(node * & head);
        list();
        ~list();
    private:
        node *head;
};
