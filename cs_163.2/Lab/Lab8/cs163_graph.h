#include "cs163_entry.h"

//Compare these structs to the ones in your answers on Page #1
struct vertex
{
      
       journal_entry * entry;        //NULL, if the vertex isn't set
       struct node * head;           //edge list
};

struct node
{
       vertex * adjacent;	  //Additional data would be needed
                              //for a weighted graph
       node * next;
};



class table
{
      public:
            /* Implement these three functions for this lab */ 
             table(int size=5);                                //Step 6
             int insert_vertex(const journal_entry & to_add);  //Step 6
             int find_location(char * key_value);              //Step 7
             int insert_edge(char * current_vertex, char * to_attach); //Step 7
             int display_adjacent(char * key_value);           //Step 8
  
            /* These functions are ALREADY implemented for you */
             ~table(void);    // Already implemented in methods.o   
             int display_all(void) const; /*This is already implemented */
      private:
              vertex * adjacency_list;
	          int list_size;

};
