#include "cs163_graph.h"
using namespace std;

/* Implement these three functions for this lab */
table::table(int size)
{
      //Allocate the adjacency list and set each
      //head pointer to NULL
    list_size = size;
    adjacency_list = new vertex[list_size];
    for(int index = 0; index < list_size; ++index)
    {
        adjacency_list[index].head = NULL;
        adjacency_list[index].entry = NULL;
    }

}

//Store the vertex at this location.
int table::insert_vertex(const journal_entry & to_add)
{

        //Place your code here
    for(int vert_index = 0; vert_index < list_size; ++vert_index)
    {
        if(!adjacency_list[vert_index].entry)
        {
            adjacency_list[vert_index].entry = new journal_entry;
            adjacency_list[vert_index].entry -> copy_entry(to_add);
        }
    }

    return 0;

}

//Attach an edge to a vertex
int table::insert_edge(char * current_vertex, char * to_attach)
{
       //Attach this vertices edge to the specified vertex
    int vertex_index = find_location(current_vertex);
    int index_to_connect = find_location(to_attach);
    
    if(vertex_index < 0 || index_to_connect < 0)
        return -1;
    
    node * edge = new node;
    edge -> adjacent = &adjacency_list[index_to_connect];

    //No paths
    if(!adjacency_list[vertex_index].head)
    {
        adjacency_list[vertex_index].head = edge;
        adjacency_list[vertex_index].head -> next = NULL;
    }

    //One or more paths
    else
    {
        edge -> next = adjacency_list[vertex_index].head;
        adjacency_list[vertex_index].head = edge;
    }

    return 0;
}

//Display all vertices adjacent to the one specified
int table::display_adjacent(char * key_value)
{

    int desired_vertex = find_location(key_value);

    if(desired_vertex < 0)
        return -1;

    if(!adjacency_list[desired_vertex].head -> next)
        cout << "No adjacent verticies!" << endl;

    else
    {
        node * current = adjacency_list[desired_vertex].head;

        while(current)
        {
            cout << "Tile: " << current -> entry -> title;
            cout << "\nNotes: " << current -> entry -> notes << endl;
            current = current -> next;
        }
    }

    return 0;
}

//Find a location in the graph
//Consider this a helper function foro all of the other member functions!
int table::find_location(char * key_value)
{
      //return the location of this particular key value 
    for(int vert_index = 0; vert_index < list_size; ++vert_index)
    {
        if( adjacency_list[vert_index].entry -> compare(key_value) )
            return vert_index;
    }

    return -1;
}


