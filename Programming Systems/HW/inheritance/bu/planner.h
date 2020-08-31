//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Time Managment System

#include "activity.h"

#ifndef PLANNER
#define PLANNER

class day
{
    public:
        day();
        day(int new_day);
        ~day();

    protected:

        int day_plan;
};

class node: public day
{
    public:
        //Default constructor
        node();
        //Copy constructor
        node(activity & add_activity, int new_day,  hobby & n_fun, work & n_job, school & n_education, int type);
        ~node();
        //Return next ptr
        node *& go_next();
        //return previous ptr
        node *& go_prev();
        //Set current pointer to next
        void set_next(node *& current);
        //Set current pointer to previous
        void set_previous(node *& current);
        //display
        void display();
        
    protected:

        //Has an array of base case pointers
        activity ** new_activity; 
        //Dervied pointers
        work * job;
        hobby * fun;
        school * ed;
        //Next and previous
        node * next;
        node * previous;

};

// Make array (1 - n)
class planner
{
    public:
        planner(int choice);
        ~planner();
        // Insert/Add activity into planner 
        int add_activity(activity & new_activity, hobby & fun, work & job, school & education, int type);
        //Is array empty
        bool is_empty();
        //Display all
        int display();

    protected:
        node ** array;
        int size;

    private:
        int display(node * head);
        void destroy(node * & head);

};
#endif

