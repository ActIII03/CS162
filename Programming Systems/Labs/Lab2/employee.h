#include "person.h"
#include "node.h"
bool again();


class employee: public person		
{
      public:
             employee();
             employee(const employee & source);
             employee(char * name, char * street, char * zip, int id);
             employee(const person & new_employee);
             ~employee();

             bool hire(const person & a_person);
             bool probation(char * review);
             bool performance_review(char * review);
             bool quit();
             bool fired(char * documentation);  
             void display() const;        

      protected:   
              int employee_id;
              node * root;  //for the personnel records


              void display(node * root) const;
              void copy_tree(node * & dest_root, node * source_root) const;

              
};


class hourly_employee: public employee
{
      public:
             hourly_employee();
             hourly_employee(const person & input); //set up hourly emp.
             hourly_employee(const employee & input); 
             hourly_employee(int max_hours);   //set max hours 
             bool hours_worked(int num_hours); //how many hours worked?
             void set_pay_rate(float rate);    //set pay rate
             void authorize_overtime();        //is overtime ok?

             int overtime_worked() const;      //how much overtime worked?
             int hours_worked() const;         //how many hours worked?
             void display() const;             //display all info
      protected:
             int hours;
             int max_hours_allowed; //without overtime authorized
             bool overtime_ok;      //has overtime been authorized?
             float pay_rate;
};
