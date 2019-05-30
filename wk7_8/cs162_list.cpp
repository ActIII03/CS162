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
    cin.ignore();
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

//Activity type constructor
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
    if(name != NULL)
    {
        delete [] name;
        name = NULL;
    }
    if(type != NULL)
    {
        delete [] type;
        type = NULL;
    }
    if(location != NULL)
    {
        delete [] location;
        location = NULL;
    }
}

void list::destroy(node * & head)
{
    if(!head)
        return;
    else
    {
        node * temp = head -> next;
        delete head;
        head = NULL;
        destroy(temp);
    }
        
}

list::list()
{
    head = NULL;
}

list::~list()
{

    if(head != NULL)
    {
        destroy(head);
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
    cout << "Length(Total Minutes): " << endl;
    cin >> length;
    cin.ignore();

    //Copy hold
    current -> new_act.copy_act(name, type, location, length);

    //Pass by value temp struct to make nodes
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
        return;
    }

    //Is there only one node
    if(head -> next != NULL)
    {
        node * temp = current; //Insert data here
        temp -> next = head;
        head = temp;
        return;
    }

    //Is there multiple nodes?
    else
    {
        node * temp = current;
        current -> next = head;
        head = current;
    }
}

//Display function
void list::display()
{
    //Create a pointer starting at the head
    node * current = head;
    int number = 1;  //Just a display variable

    //Traverse to the last node is null
    while(current != NULL)
    {
        cout << "(" << number << ")" << " Name: " << current -> new_act.name << "\n ";
        cout << "Type: " << current -> new_act.type << "\n ";
        cout << "Location: " << current -> new_act.location << "\n ";
        if(current->new_act.length < 60)
            cout << "Length: " << current->new_act.length << " minutes\n";
        else
            cout << "Length: " << (current->new_act.length / 60) << " hours\n\n";
        ++number;
        current = current -> next;  //Advance pointer to next node
    }
}

//Search by type function
void list::search()
{
    node * current = head;
    char type[100];  //Get user's input for what type they wish to display

    cout << "Please enter a type of activity you would like to display: ";
    cin.get(type, 100, '\n');
    cin.ignore();

    //1st case: Is head NULL
    if(head == NULL)
        cout << "List is empty!" << endl;

    //If there is one more nodes this condition will execute
    else
    {
        while(current != NULL)   //Traverse to the last node
        {
            //String compare 
            if(!(strcmp(current -> new_act.type, type)))
            {
               cout << "Name: " << current -> new_act.name
                    << "\nType: " << current -> new_act.type
                    << "\nLocation: " << current -> new_act.location << endl;
                    if(current -> new_act.length < 60)
                        cout << "Length: " << current -> new_act.length << " minutes\n";
                    else
                        cout << "Length: " << current -> new_act.length << " hours\n";
            }
            current = current -> next;   //Advance pointer
        }
    }
}

