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

outdoor_activity::outdoor_activity()
{
    head = NULL;
    num_of_activities = 0;
    return;
}

outdoor_activity::~outdoor_activity()
{
    activity_node *temp = head;

    if(head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

}
//Add read-in message
void outdoor_activity::read_in(activity_type read_act[])
{
    activity_type read_act;
    //Example of reading in one member to 
    char buffer[100];
    cout << "Name: " << endl;
    cin.get(buffer, 100, '\n');
    cin.ignore();
    //read_act.name = new char[strlen(buffer) + 1];
    strcpy(read_act.name, buffer);

    cout << "Name: " << read_act.name << endl;
}
/*
outdoor_activity::destructor()
{

}*/

