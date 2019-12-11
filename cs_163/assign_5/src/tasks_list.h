//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

#ifndef TASKS
#define TASKS
class TasksToDo
{

    public:

        //Constructors and Destructors
        TasksToDo();
        ~TasksToDo();

        //Create tasks
        int create_tasks(char * new_task, char * new_description);

        //Copy Entry
        int copy_entry(const TasksToDo & a_new_task);

        //Compare Tasks
        bool compare(char * is_match);

        char * task;
        char * description;

};
#endif

int menu();
