//Name: Armant Touche
//Class: CS 163
//Instructor: Karls Fant
//Description:

#include "tasks_list.h"


struct vertex
{
    TasksToDo * new_task;
    struct node * head;
};

struct node
{
    vertex * adjacent;
    node * next;
};

class table
{
    public:
        
        //Constructor and Destructor
        table(int size = 15);
        ~table();
        
        //Insert vertex
        int insert_vertex(TasksToDo & new_task);

        //Find location
        int find_location(char * key);

        //Insert path
        int insert_path(char * vertex, char * to_attach);

        //Display adjacent tasks
        int display_adjacent(char * key);

        //Display All tasks
        int display_all();

    private:

        vertex * adjacency_list;
        int list_size;

};
