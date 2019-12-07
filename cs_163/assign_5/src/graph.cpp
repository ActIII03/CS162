//Name: Armant Touche
//Class: CS 163
//Instructor: Karls Fant
//Description:

#include "graph.h"

node::node()
{
    next = NULL;
}

table::table(int size)
{

    num_of_tasks = -1;
    list_size = size;
    adjacency_list = new vertex[list_size];
    
    for(int index = 0; index < list_size; ++index)
    {
        adjacency_list[index].new_task = NULL;
        adjacency_list[index].head = NULL;
    }

}

table::~table()
{


}


int table::insert_vertex(TasksToDo & new_task)
{

    bool success_insert = false;

    for(int index = 0; !success_insert && index < list_size; ++index)
    {
        if(!adjacency_list[index].new_task)
        {
            adjacency_list[index].new_task = new TasksToDo;
            adjacency_list[index].new_task -> copy_entry(new_task);
            success_insert = true;

        }
    }

    ++num_of_tasks; 
    return 0;

}

int table::find_location(char * key)
{

    return 0;

}

int table::insert_path()
{

    node * edge = new node;
    
    //Hook up previous entry
    edge -> adjacent = &adjacency_list[num_of_tasks - 1]; 

    //Connect to newest entry
    edge -> next = adjacency_list[num_of_tasks].head;

    return 0;

}

int table::display_adjacent(char * key)
{

    return 0;

}

int table::display_all()
{

    return 0;

}
