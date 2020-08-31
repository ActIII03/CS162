//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Time Managment System
#include "planner.h"


day::day()
{
}

day::~day()
{
}

day::day(int new_day)
{
    day_plan = new_day;
}

node::node()
{
    new_activity = new activity * [2];
    job = NULL;
    fun = NULL;
    ed = NULL;
    next = NULL;
    previous = NULL;
}

node::node(activity & add_activity, int new_day,  hobby & n_fun, work & n_job, school & n_education, int type): day(new_day)
{

    new_activity = new activity * [2];

    new_activity[0] = new activity(add_activity);

    //Check derived type and copy it
    if(type == 1)
    {
        hobby * fun = new hobby(n_fun);
        //copy(*add_activity[1]);
        new_activity[1] = &*fun;
    }
    else if(type == 2)
    {
        work * job = new work(n_job);
        //job -> copy(*add_activity[1]);
        new_activity[1] = &*job;
    }
    else if(type == 3)
    {
        school * education = new school(n_education);
        //education -> copy(*add_activity[1]);
        new_activity[1] = &*education;
    }

    next = NULL;
    previous = NULL;
}

node *& node::go_next()
{
    return next;
}

node *& node::go_prev()
{
    return previous;
}

void node::set_next(node *& current)
{
    next = current;
}

void node::set_previous(node *& current)
{
    previous = current;

}

void node::display()
{
    new_activity[0] -> display();
    new_activity[1] -> display();
}

node::~node()
{
    if(new_activity)
    {
        delete new_activity[0];
        delete new_activity[1];
        delete [] new_activity;
    }
}

planner::planner(int choice)
{
    size = 7;
    if(choice > 0)
        size = choice;

    array = new node * [size];
    
    for(int index = 0; index < size; ++index)
        *(array + index) = NULL;
}

planner::~planner()
{
    for(int index = 0; index < size; ++index)
        destroy(array[index]);
    delete [] array;
}

int planner::add_activity(activity & new_activity, hobby & fun, work & job, school & education, int type)
{

    int day;
    bool flag;

    do
    {
        cout << "Which day from now would you add to?(1 - n): ";
        cin >> day;
        cin.ignore(MAX, '\n');
        if(day > size)
        {
            flag = false;
            cout << "That is outside the range of days!";
        }
        else
            flag = false;

    }while(flag);



    node * new_entry = new node(new_activity, day, fun, job, education, type);

    //NO entry
    if(array[day - 1] == NULL)
    {
        new_entry -> set_next(array[day - 1]);
        array[day - 1] = new_entry;
    }
    //At least one item
    else
    {
        //Set next
        new_entry -> set_next(array[day - 1]);
        //Set previous
        array[day - 1] -> set_previous(new_entry);
        //Set head to new entry
        array[day - 1] = new_entry;
    }

    return 0;
}

bool planner::is_empty()
{
    bool flag = true; 
    
    for(int index = 0;index < size; ++index)
    {
        if( *(array + index) )
            flag = false;
    }

    return flag;
}

int planner::display()
{

    if(is_empty())
        return -99;

    int result = 0;

    for(int index = 0; index < size; ++index)
        display(array[index]);  

    return result;
}
int planner::display(node * head)
{

    int result = 0;

    if(!head)
        return result + 1;
   
    head -> display();

    result += display(head -> go_next());

    return result;
}

void planner::destroy(node * & head)
{
    if(!head)
        return;
    node * temp = head;
    head = head -> go_next();
    delete temp;
    return destroy(head);
}

