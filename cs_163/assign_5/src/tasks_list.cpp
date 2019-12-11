//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include "tasks_list.h"

TasksToDo::TasksToDo()
{
    
    task = NULL;
    description = NULL;

}


TasksToDo::~TasksToDo()
{
    if(task)
    {
        delete [] task;
        task = NULL;
    }

    if(description)
    {
        delete [] description;
        description = NULL;
    }

}
                                                   
int TasksToDo::create_tasks(char * new_task, char * new_description)
{

    task = new char[strlen(new_task) + 1];
    strcpy(task, new_task);
    description = new char[strlen(new_description) + 1];
    strcpy(description, new_description);

    return 0;

}
                                                   
int TasksToDo::copy_entry(const TasksToDo & a_new_task)
{
    
    task = new char[strlen(a_new_task.task) + 1];
    strcpy(task, a_new_task.task);
    description = new char[strlen(a_new_task.description) + 1];
    strcpy(description, a_new_task.description);

    return 0;

}
                                                   
bool TasksToDo::compare(char * is_match)
{
    if(!(strcmp(task, is_match)))
        return true;
    else
        return false;

}

int menu()
{
    int choice = 0;
    cout << "Options: \n(1) Add task \n(2) Display All task\n(3) Quit"
         << "\nChoices(1-3): ";
    cin >> choice;
    cin.ignore(100, '\n');

    return choice;
}
