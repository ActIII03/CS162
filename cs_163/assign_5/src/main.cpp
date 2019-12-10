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

    char task[100], description[500], connect_to[100];
    bool quit = false, no_task = true;
    

    do
    {
        switch(menu())
        {
            case 1:
                //Add task
                cout << "Enter a task: ";
                cin.get(task, 100, '\n');
                cin.ignore(100, '\n');
                cout << "Enter a description of the task: ";
                cin.get(description, 100, '\n');
                cin.ignore(100, '\n');
                new_task.create_tasks(task, description);

                if(no_task)
                {
                    task_lists.insert_vertex(new_task);
                    no_task = false;
                }

                //If more than one, start a direct path from first task to last inputted task
                else
                {
                    cout << "Which of the previous tasks can this current one be related to?: ";
                    cin.get(connect_to, 100, '\n');
                    cin.ignore(100, '\n');
                    task_lists.insert_vertex(new_task);
                    task_lists.insert_path(task, connect_to);
                }
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
