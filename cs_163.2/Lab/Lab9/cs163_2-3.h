//This class was prepared to contain BOTH a binary search tree
//and a 2-3 tree for our use. Again, the underlying data will
//be a simple integer.
//
//Please see below for the prototypes that you will be implementing!
//Much of the code has already been written, so follow the lab guidelines
//closely!

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>


struct node23 //for a 2-3 tree
{
    int data[2];   	    //Two data items. If data[1] is zero, that
                        //means there is no data.
    node23 * child[3];  //Three child pointers. child[0] is "left"
		                //child[1] is "middle" and child[2] is "right"
			            //If child[1] is NULL, there is only 1 data item
};

class table
{
    public:
        // *** You will need to write these wrapper functions
        // Remember that means to call the private recursive member functions
    	int display_23();      //Display all nodes with no children in 2-3 tree

  	    bool find_largest();   //Return true if the root's largest value appears more than once
        int copy(const table & source); //Copies the argument into the current ojbect


	    //  ***These functions have been written for you  already
	    table();
	    ~table();
	    int build(); 
	    int display();  

    private:
        node23 * root23;	//a 2-3 tree

	    //  ***These are the functions you will be writing recursively!
        int display_23(node23 * root);      
	    int deallocate_23(node23 * & root); 
        bool find_largest(node23 * root, int match); 
        int copy(node23 * & dest_root, node23 * source_root);  //Challenge

};






 
  

