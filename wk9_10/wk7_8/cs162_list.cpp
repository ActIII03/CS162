#include "cs162_list.h"

//Greeting module
void greetings()
{
    cout << "Welcome to PDX Event Repo, where you can keep track of all the fun activities here Oregon."
         << "\nThe items this program keeps track of are: \n\n\n- Name of Event \n- Month of event \n- Day the event happens\n\n";
}

//Get's user's int-value input
int menu(int & decision)
{
    cout << "\nWhich option would you like to pick?:\n"
         << "(1)New Entry\n(2)Display\n(3)Search\n(4)Remove\n(5)Quit\nChoice(1-5): ";
    cin >> decision;
    cin.ignore();
    return decision;
}

//Activity type constructor
event_type::event_type()
{
    name = NULL;
    month = NULL;
    day = 0;
    counter = 0;
}


//Activity object destructor
event_type::~event_type()
{
    if(name != NULL)
    {
        delete [] name;
        name = NULL;
    }
    if(month != NULL)
    {
        delete [] month;
        month = NULL;
    }
}

//Destructor helper using recursion
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

//List class constructor
list::list()
{
    head = NULL;
}

//List class destructor
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

    //Arrays for reading 
    char name[100];
    char month[100];
    int day;

    cout << "Name of Event: " << endl;
    cin.get(name, 100, '\n');
    cin.ignore();
    cout << "Month of Event: " << endl;
    cin.get(month, 100, '\n');
    cin.ignore();
    cout << "Day Event happens: " << endl;
    cin >> day;
    cin.ignore();

    //Copy hold
    current -> new_event.copy_event(name, month, day);

    //Pass by value temp struct to make nodes
    insert(current);
}

//Read in helper module
void event_type::copy_event(char t_name[], char t_month[], int t_day)
{
    name = new char[strlen(t_name) + 1];  
    strcpy(name, t_name);

    month = new char[strlen(t_month) + 1];  
    strcpy(month, t_month);

    day = t_day;
    ++counter;
    
    if(counter == 1)
        cout << "\n\nTotal of " << counter << " activity exist\n\n";
    else
        cout << "\n\nTotal of " << counter << " activities exist\n\n";

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

    if(!head)
    {
        cout << "List is empty!";
        return;
    }

    //Traverse to the last node 
    while(current != NULL)
    {
        cout << "\n(" << number << ")\n" << " Name: " << current -> new_event.name << "\n ";
        cout << "Month & Day: " << current -> new_event.month << " " << current -> new_event.day << endl;
        ++number;
        current = current -> next;  //Advance pointer to next node
    }
}

//Search by type function
void list::search()
{
    node * current = head;
    char month[100];  //Get user's input for what type they wish to display
    int day = 0;

    cout << "Please enter a Month to see if there is an event that month: ";
    cin.get(month, 100, '\n');
    cin.ignore();
    cout << "Please enter a day: ";
    cin >> day;
    cin.ignore();

    //1st case: Is head NULL
    if(head == NULL)
        cout << "List is empty!" << endl;

    //If there is one more nodes this condition will execute
    else
    {
        while(current != NULL)   //Traverse to the last node for month and date
        {
            //String compare  type with user's input
            if(!(strcmp(current -> new_event.month, month)) && current -> new_event.day == day )
            {
                cout << "\nMatch: \n"
                     << "Name: " << current -> new_event.name
                     << "\nMonth: " << current -> new_event.month 
                     << "\nDay: " << current -> new_event.day << endl;
            }
            current = current -> next;   //Advance pointer
        }
    }
}

//Removal function
void list::remove()
{
    char name[100];

    //Empty list
    if(!head)
        return;

    else
    {
        display();
        node * current; 
        node * previous;

        cout << "Please enter the name of the event you wish to delete: ";
        cin.get(name, 100, '\n');
        cin.ignore();

        //Removal at the beginning
        if(!(strcmp(head -> new_event.name, name)))
        {
            current = head -> next;
            delete head;
            head = current;
            return;
        }

        //Removal elsewhere
        else
        {
            current = head -> next;

            while(current && strcmp(current -> new_event.name, name) != 0)
            {
                previous = current;
                current = current -> next;
            }

            if(!current)
            {
                previous -> next = current -> next;
                delete current;
                return;
            }
        }
    }
}
