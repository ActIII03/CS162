//This class was prepared for a working with both a binary search
//tree and a 2-3-4 tree implementation of
//a table abstraction. For the lab we will keep the underlying data
//simple - just an integer.
//
//Please see below for the prototypes that you will be implementing!
//These must be implemented before you can compile and run.

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>


struct node      
{
    int data;
    node * left;
    node * right;;
};

struct node234
{
    int data[3];
    node234 * child[4];
};

class table
{
    public:

	// ***YOU NEED TO WRITE THESE WRAPPER functions
        //These first three are binary search tree functions
        void display_largest();          //Step 1
        int count_root();                //Step 2
        void copy(table & copy_from);    //Step 3

        //Now 2-3-4 functions:
  	    int count_3_data();	         //Step 4 Return the count
  	    int height();                    //Step 5 Challenge
        int copy_234(table & copy_from);     //Step 6 Challenge

  	//  ***These functions have been written for you   
	    table();
     	~table();
      	int build();           //All of these functions are provided for you
        int display();
    private:

	    node * root;       //Binary search tree
        node234 * root234; //2-3-4 tree  		 
  

	//  ***These are the functions you will be writing recursively!
	    void display_largest(node * root);          //Step 1 
	    int count_root(node * root, int match);     //Step 2
	    void copy(node * & destination, node * source); //Step 3

  	    int count_3_data(node234 * root);	        //Step 4
  	    int height(node234 * root);                    //Step 5
        int copy(node234 * & destination, node234 * source);      //Step 6
};
