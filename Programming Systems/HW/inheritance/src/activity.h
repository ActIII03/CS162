//Name: Armant Touche
//Class: CS 202
//Instructor: Karla Fant
//Program: Time Managment System

//Typcial Libraries
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstddef>
#include <cstdlib>

using namespace std;

#ifndef ACTIVITY
#define ACTIVITY

const int MAX = 100;

struct act_time
{
    int length_hour;
    int length_minute;
    int hour;
    int minute;
    bool midday;
};

//Base class for three hobbies: (i) Work (ii) Hobby (iii) School
class activity
{
    public:
        //Default Constructor
        activity();
        //User-supplied
        activity(char * act_name, char * act_type, struct act_time & new_time);
        //Copy constructor
        activity(activity & to_copy);
        //Destructor
        virtual ~activity();
        //Read-in function
        virtual void read();
        //Display
        virtual void display();
        //Compare activity
        int compare(const activity & to_compare);
        //Copy object 
        virtual void copy(activity & dest);
        //Validate datatype
        virtual int check_datatype();

    protected:

        char * name_of_activity;
        char * category;
        act_time new_act_time;
};

//Derivation
class hobby: public activity
{
    public:
        hobby();
        hobby(bool items);
        // Create copy constructor
        hobby(hobby & fun);
        ~hobby();
        //Read in inherited from base
        void read();
        //Display inherited from base class 
        void display();
        //Copy function inherited from base class
        void copy(activity & dest);
        //Validate datatype
        int check_datatype();

    protected:
        bool require_items; 
};

//Derivation
class work: public activity
{
    public:
        work();
        work(char * j_name);
        // copy constructor
        work(work & job);
        //work(activity & job);
        ~work();
        //Read in inherited from base
        void read();
        //Display inherited from base class 
        void display();
        //Copy function inherited from base class
        void copy(work & dest);
        //Check datatype
        int check_datatype();

    protected:
        char * job_name;
};

//Derivation
class school: public activity
{
    public:
        school();
        // User-supplied constructor
        school(char * cl_name, char * assign_name);
        // Create copy constructor
        school(school & education);
        ~school();
        //Read in inherited from base
        void read();
        //Display inherited from base class
        void display();
        //Copy function inherited from base class
        void copy(activity & dest);
        //Check datatype
        int check_datatype();

    protected:
        char * class_name;
        char * assignment;
};
#endif 


//Helper functions
void read_activity(activity & read_in);
void display_activity(activity * one_activity[]);
void copy_activity(activity & to_copy);
bool again();

