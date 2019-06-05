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
    name = NULL;
    type = NULL;
    location = NULL;
    leng_time = NULL;
    counter = NULL;
}

activity_type::~activity_type()
{

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
void activity_type::read_in(activity_type & temp_act)
{
    //Node to hold data
    node * current = new node;
    list list_mgmt;

    //Example of reading in one member to 
    char buffer[100];

    cout << "Name: " << endl;
    cin.get(buffer, 100, '\n');
    cin.ignore();
    current -> new_act.name = new char[strlen(buffer) + 1];
    strcpy(current -> new_act.name, buffer);
   
    //Pass by ref temp struct to make nodes
    list_mgmt.insert(temp_act);
}

void activity_type::copy_act(activity_type & to_copy)
{
    cout << "Name: " << to_copy.name << endl;
}

void list::insert(activity_type & to_add)
{
    node *current, *previous, *temp;
    activity_type copy_act;

    if(head == NULL)
    {
        head = new node;
        head -> copy_act(to_add);
        head -> next = NULL;
    }
}
