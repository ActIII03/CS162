#include "cs163_graph.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the adjacency list and set each
      //head pointer to NULL
      
    list_size = size;
    adjacency_list = new vertex[list_size];
    for(int index = 0; index < list_size;++index)
    {
        adjacency_list[index].entry = NULL;
        adjacency_list[index].head = NULL;
    }

}

//Store the vertex at this location.
int table::insert_vertex(const journal_entry & to_add)
{

    int result = 0;
    bool insert = false;

    for(int index = 0; index < list_size && insert == false; ++index)
    {
        if(!adjacency_list[index].entry)
        {
            adjacency_list[index].entry = new journal_entry;
            adjacency_list[index].entry -> copy_entry(to_add);
            ++result;
            insert = true;
        }
    }
    return result;

}

//Attach an edge to a vertex
int table::insert_edge(char * current_vertex, char * to_attach)
{

    int vert_index = find_location(current_vertex), index_to_connect = find_location(to_attach);

    if( vert_index < 0 || index_to_connect < 0)
        return -1;

    node * edge = new node;

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

//Display all vertices adjacent to the one specified
int table::display_adjacent(char * key_value)
{

    int desired_index = find_location(key_value);

    if(desired_index < 0)
        return -99;

    if(!adjacency_list[desired_index].head -> next)
        return -99;
    else
    {
        node * current = adjacency_list[desired_index].head;

        while(current)
        {
            current -> adjacent -> entry -> display();
            current = current -> next;
        }
    }
    return 0;
}

//Find a location in the graph
//Consider this a helper function foro all of the other member functions!
int table::find_location(char * key_value)
{
    int vert_index = -1;
    for(int index = 0; index < list_size; ++index)
    {
        if(adjacency_list[index].entry)
        {
            if(adjacency_list[index].entry -> compare(key_value))
                vert_index = index;
        }
    }

    return vert_index;
}

int table::depth_traverse()
{

    int flag_arr[] = { 0, 0, 0, 0, 0 };

    for(int index = 0; index < list_size; ++index)
    {
        if(adjacency_list[index].entry && flag_arr[index] == 0)
        {
            adjacency_list[index].entry -> display();
            flag_arr[index] = 1;
        }
    }
    return 0;

}
