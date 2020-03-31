//Name: Armant Touche
//Class: CS 163
//Instructor: Karla Fant
//Description: Graph ADT interface

#include "course.h"

struct vertex
{
    Course * course_entry;
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
        table(int size = 5);
        ~table();

        //Insert vertex
        int insert_vertex(Course & to_add);

        //Find vertex location
        int find_location(char * search);

        //Insert edge
        int insert_edge(char * current_vertex, char * to_attach);

        //Display adj. list
        int display_adj(char * key_value);

    private:

        //Display adj. list recursively
        void display(node * head);

        vertex * adjacency_list;
        int list_size;
};
