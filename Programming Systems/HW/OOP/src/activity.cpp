//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Time Managment System
#include "activity.h"

activity::activity()
{
    name_of_activity = NULL;
    category = NULL;
    length = 0;

}

activity::activity(char * act_name, char * act_type, int act_len)
{
    name_of_activity = new char[strlen(act_name) + 1];
    strcpy(name_of_activity, act_name);
    category = new char[strlen(act_type) + 1];
    strcpy(category, act_type);
    length = act_len;
}

activity::activity(const activity & to_copy)
{
    name_of_activity = new char[strlen(to_copy.name_of_activity) + 1];
    strcpy(name_of_activity, to_copy.name_of_activity);
    category = new char[strlen(to_copy.category) + 1];
    strcpy(category, to_copy.category);
    length = to_copy.length;


}

void read

activity::~activity()
{
    if(name_of_activity)
        delete name_of_activity;
    if(category)
        delete category;
}

hobby::hobby()
{

}

hobby::~hobby()
{

}

work::work()
{

}

work::~work()
{

}

school::school()
{
    assignment = NULL;

}

school::school(char * assign_name)
{
    assignment = new char[strlen(assign_name) + 1];
    strcpy(assignment, assign_name);
}

school::~school()
{

}
