#include "cs162_list.h"

void greetings()
{
    cout << "Welcome to PDX Activities Repo, where you can keep track of all the fun activities here Oregon."
         << "\nThe items this program keeps track of are: \n- Name of Activity \n- Location \n- Type of Activity"
         << "\n- Length of activity.\n\n\n";
}

int menu(int & decision)
{
    cout << "Which option would you like to pick?:\n"
         << "(1)New Entry\n(2)Display\n(3)Search\n(4)Quit\nChoice(1-4): ";
    cin >> decision;
    return decision;
}

bool are_you_sure()
{
    char choice = 'Y';
    cout << "Would you like to continue?:(Y/N)";
    cin >> choice;
    choice = toupper(choice);

    if(choice == 'Y')
        return true;
    else
        return false; 
}

activity_type::activity_type()
{
    name = NULL;
    type = NULL;
    location = NULL;
    length = 0;
    counter = 0;   
}

activity_type::~activity_type()
{
}


list::list()
{
    head = NULL;
}

list::~list()
{

    if(head == NULL)
    {
        cout << "List is empty" << endl;
    }

}
//Add read-in message
void list::read_in() //Empty
{
    //Node to hold data
    node * current = new node;

    //Example of reading in one member to 
    char name[100];
    char type[100];
    char location[100];
    int length;

    cout << "Name: " << endl;
    cin.get(name, 100, '\n');
    cin.ignore();
    cout << "Type: " << endl;
    cin.get(type, 100, '\n');
    cin.ignore();
    cout << "Location: " << endl;
    cin.get(location, 100, '\n');
    cin.ignore();
    cout << "Length: " << endl;
    cin >> length;
    cin.ignore();

    //Copy hold
    current -> new_act.copy_act(name, type, location, length);

    //Pass by ref temp struct to make nodes
    insert(current);
}

void activity_type::copy_act(char t_name[], char t_type[], char t_location[], int t_length)
{
    name = new char[strlen(t_name) + 1];  
    strcpy(name, t_name);
    location = new char[strlen(t_location) + 1];  
    strcpy(location, t_location);

    type = new char[strlen(t_type) + 1];  
    strcpy(type, t_type);

    length = t_length;
    ++counter;
}

//Insert At the the beginning
void list::insert(node * current)
{
    
    //Is there no nodes?
    if(head == NULL)
    {
        head = current;
        head -> next = NULL;
    }

    //Is there only one node
    if(head -> next != NULL)
    {
        node * temp = current; //Insert data here
        temp -> next = head;
        head = temp;
    }

    //Is there multiple nodes?
    else
    {
        node * temp = current;
        current -> next = head;
        head = current;
    }
}

void list::display()
{
    node * current = head;

    while(current != NULL)
    {
        cout << "Name: " << current -> new_act.name << endl;
        current = current -> next;
    }
}
