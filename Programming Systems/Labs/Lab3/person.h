#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>



//This class interface is a subset of the classes used for the first
//three labs
                                                                                   
//What I wanted to show you with these classes is that there is much more to       
//OOP and classes than creating just setters and getters. In fact, you will notice 
//with my design that I never have "get" functions. If you have a "get" function   
//always ask youself why is it there? Why does another function need to get my     
//hidden data? Based on that answer, you can add the necessary functionality to    
//the class in general.                                                            
                                                                                   
//In this subset, there is an address class which keeps track of an individuals    
//address(street and zip for now). To make a full address class, you would want to 
//add a street number, city, and state. Then there is a name class.         
class address
{
      public:
             address();
             address(char * street, char * zip);
             address(const address & to_copy);
             ~address();
             void change_address(char * new_street, char * new_zip);
             void copy_address(const address & to_copy);
             bool check_zip(const char * zip_to_compare) const;
             void read();
             void display() const;
      protected:
              char * street;
              char * zip;
};

class name
{
      public:
             name();
             name(char * initial_name);
             name(const name & to_copy);
             ~name();
             void change_name(char *new_name);
             void set_name(const name & setup_name);
             bool find_by_name(const char * to_compare) const;
             int find_by_name(const name & to_compare) const;
             void read();
             void display() const;
      protected:
              char * a_name;
};


//The person class is derived from a name but "has" an address. This is designed
//this way because the name functionality is used much more frequently than the
//address for this particular implementation of a person. 

class person: public name			
{
      public:
             person();
             person(char * name, char * street, char * zip);
             person(const name &);
            
             void copy_person(const person & to_copy);
             bool find_by_zip(const char * zip_to_compare) const;
             void read();
             void display() const;
	     void change_address(char * street, char * zip);
      protected:
             address my_address;
}; 

