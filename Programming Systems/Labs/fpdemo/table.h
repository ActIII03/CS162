//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class table
{
    public:
    	//These functions are supplied already
    	table();			//supplied
    	~table();			//supplied
        void build(); 		//supplied
        void display(); 	//supplied


/* ************** PLACE YOUR PUBLIC PROTOTYPE HERE ***************** */
        int remove_largest();
        int remove_smallest();
        int find_root_ios();
        int is_max(int l_tree, int r_tree);
        int copy_bst(table & src);
        float get_height();
 
 
 	private:
 		node * root;

/* ************** PLACE YOUR PRIVATE PROTOTYPE HERE ***************** */
        int remove_largest(node *& current, node *& previous);
        int remove_smallest(node *& current, node *& previous);
        int find_root_ios(node * current);
        int traverse_left(node * current);
        int copy_bst(node * src, node *& dest);
        int get_height(node * current, float & sum, int & count);

};
  

