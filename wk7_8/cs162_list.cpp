#include "cs162_list.h"

void greetings()
{
    cout << "Welcome to PDX Activities Repo, where you can keep track of all the fun activities here Oregon."
         << "\nThe thing this program keeps track of is: \n(1) Name of Activity \n(2) Location \n(3) Type of Activity"
         << "\n(4) Length of activity. " << endl;
}

/*bool are_you_sure()
{

}*/

activity_type::activity_type()
{
    char *node;
    char *type;
    char *location;
    int *leng_time;
    int counter = 0;
}

list::list()
{
    head = NULL;
    return;
}

list::~list()
{
    node *temp = head;

    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

}
//Add read-in message
void list::read_in()
{
    node * current = new node;

    //Example of reading in one member to 
    char buffer[100];

    cout << "Name: " << endl;
    cin.get(buffer, 100, '\n');
    cin.ignore();
    current -> new_act.name = new char[strlen(buffer) + 1];
    strcpy(current -> new_act.name, buffer);
    
    insert(current -> new_act);
}

void list::insert(activity_type & to_insert)
{
    node *current, *previous, *temp;
    if(head == NULL)
    {
        head = new node;
        head ->  ;
        head -> next = NULL;
    }
}

/*
list::~list()
{

}*/

