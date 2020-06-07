//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: ADT implementation

#include "graph.h"

table::table(int size)
{
    list_size = size;
    adjacency_list = new vertex[list_size];
    for(int index = 0; index < list_size; ++index)
    {
        adjacency_list[index].course_entry = NULL;
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
            node * temp;

            while(current)
            {
                temp = current -> next;
                delete current;
                current = temp;
            }
        }
    }

    //Destory vertices
    for(int index = 0; index < list_size; ++index)
    {
        if(adjacency_list[index].course_entry)
        {
            adjacency_list[index].course_entry -> delete_class();
            delete adjacency_list[index].course_entry;
        }
    }

    delete [] adjacency_list;

}

int table::insert_vertex(Course & to_add)
{
    int result = 0;
    bool insert = true;

    for(int index = 0; insert == true && index < list_size; ++index)
    {
        if(!adjacency_list[index].course_entry)
        {
            adjacency_list[index].course_entry = new Course;
            adjacency_list[index].course_entry -> copy_entry(to_add);
            ++result;
            insert = false;
        }
    }

    return result;
}

int table::find_location(char * search)
{
    int vert_index = -1;
    for(int index = 0; index < list_size; ++index)
    {
        if(adjacency_list[index].course_entry)
        {
            if(adjacency_list[index].course_entry -> compare(search) == 0)
                vert_index = index;
        }
    }

    return vert_index;
}

int table::insert_edge(char * current_vertex, char * to_attach)
{
    int vert_index = find_location(current_vertex), index_to_connect = find_location(to_attach);

    if(vert_index < 0 || index_to_connect < 0)
            return -99;
    
    node * edge = new node;;

    edge -> adjacent = &adjacency_list[index_to_connect];

    // No paths
    if(!adjacency_list[vert_index].head)
    { 
        adjacency_list[vert_index].head = edge;
        adjacency_list[vert_index].head -> next = NULL;
    }
    //One or more paths
    else
    {
        //Insert at beginning of adj list
        edge -> next = adjacency_list[vert_index].head;
        adjacency_list[vert_index].head = edge;
    }
    return 0;

}

int table::display_adj(char * key_value)
{
    int desired_index = find_location(key_value);

    if(desired_index < 0)
        return -99;

    if(!adjacency_list[desired_index].head)
        return -99;
    else
    {
        node * current = adjacency_list[desired_index].head;
        display(current);
    }
    return 0;

}

void table::display(node * head)
{
    if(!head)
        return;
    
    head -> adjacent -> course_entry -> display();

    return display(head -> next);
}
