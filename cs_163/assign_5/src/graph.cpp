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
    
    //Destory adjacency list
    for(int index = 0; index < list_size; ++index)
    {
        if(adjacency_list[index].head)
        {
            node * current = adjacency_list[index].head;
            node * previous;

            while(current)
            {
                previous = current;
                current = current -> next;
                delete [] previous -> adjacent -> new_task -> task;
                delete [] previous -> adjacent -> new_task -> description;
                delete previous;
            }
            adjacency_list[index].head = NULL;
        }
    }

    //Destory vertices
    for(int index = 0; index < list_size; ++index)
    {
        delete [] adjacency_list[index].new_task -> task;
        delete [] adjacency_list[index].new_task -> description;
    }
    delete [] adjacency_list;
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
    for(int vert_index = 0; vert_index < list_size; ++vert_index)
    {
        if(adjacency_list[vert_index].new_task -> compare(key))
            return vert_index;
    }
    return -1;

}

int table::insert_path(char * task, char * connect_to)
{
    
    int vert_index = find_location(connect_to);
    int index_to_connect = find_location(task);
    
    if(vert_index < 0 || index_to_connect < 0)
        return -1;

    node * edge = new node;
    
    //Hook up previous entry
    edge -> adjacent = &adjacency_list[index_to_connect]; 

    //Connect to newest entry
    if(!adjacency_list[vert_index].head)
    {
        adjacency_list[vert_index].head = edge;
        adjacency_list[vert_index].head -> next = NULL;
    }
    else
    {
        edge -> next = adjacency_list[vert_index].head;
        adjacency_list[vert_index].head = edge;
    }


    return 0;

}

int table::display_all()
{
    
    for(int index = 0; index < list_size; ++index)
    {
        /*
        if(adjacency_list[index].new_task)
        {
            cout << "Task: " << adjacency_list[index].new_task -> task
                 << "\nDescription: " << adjacency_list[index].new_task -> description << endl;

            if(adjacency_list[index].head)
                display_recursive(adjacency_list[index].head);
        */

        if(adjacency_list[index].head)
        {
            cout << "Task: " << adjacency_list[index].new_task -> task
                 << "\nDescription: " << adjacency_list[index].new_task -> description << endl;
            display_recursive(adjacency_list[index].head);
        }
    } 

    return 0;

}

void table::display_recursive(node * head)
{
    if(!head) 
        return;

    cout << "Task: " << head ->  adjacent -> new_task-> task
         << "\nDescription: " << head -> adjacent -> new_task -> description << endl;
    display_recursive(head -> next);
}