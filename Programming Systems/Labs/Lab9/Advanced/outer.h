#include "inner.h"

/* This file contains the definition of the outer
 * class, as well as its descendents.
 *
 * Author: Mel Flygare <mflygare@pdx.edu>
 **/

// This class represents the outer array of an array
// of objects. Inherit from this to create an array
// of another type of object.
class Outer
{
    public:
        Outer(int N);
        ~Outer();
        void display();
        void fill_array();        

        // These have been written for you
        unsigned long actual_sum();
        unsigned int actual_max();

        // Complete these functions
        unsigned long sum_all();
        unsigned int max_all();
        double average_all();

    protected:
        Inner** array;  // array of some data structure
        int N;          // Number of threads to use
};

class ARR : public Outer {
    public:
        ARR(int N); // Written for you
};

class BST_arr : public Outer {
    public:
        BST_arr(int N); // Written for you
};
