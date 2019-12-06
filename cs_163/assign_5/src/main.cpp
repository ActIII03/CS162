//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description:


#include "tasks_list.h"
#include "graph.h"

int main()
{
    
    table task_lists;
    TasksToDo new_task, a_task;

    char task[100], description[500];
    bool quit = false;


    do
    {
        switch(menu())
        {
            case 1:
                //Add task
                cout << "Enter a task: ";
                cin.get(task, 100, '\n');
                cin.ignore(100, '\n');
                new_task.create_tasks(task, description);

                break;

            case 2:
                //Display adjacent task
        
                break;

            case 3:
                //Display all tasks

                break;

            case 4:
                //quit
                quit = true;
                break;
        }
    }while(!quit);

    return 0;

}
