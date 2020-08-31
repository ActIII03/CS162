#include "person.h"
#include "node.h"
bool again();



//This file (employee.h) has the classes discussed during the first part
//of this lab. Namely we have classes to manage different types of
//employees at a local department store. 

//Notice for this lab there is a self-similar functionality between
//the derived classes of the employee class, making the employee the
//hub for dynamic binding to take place. Therefore, the virtual
//functios should be in the employee class.


class employee: public person		
{
      public:
             employee();
             employee(const employee & source);
             employee(const person & source);
             employee(char * name, char * street, char * zip, int id);

             //These are not dynamically bound because the base class
             //manages all of the functionality
             bool hire(const person & a_person);
             bool probation(char * review);
             bool performance_review(char * review);
             bool quit();
             bool fired(char * documentation);  

             //These are virtual functions that also have a meaning in
             //the base class
             virtual void display() const;  
             virtual ~employee();           

             //These functions don't make sense here. Instead, the derived classes
             //must perform these operations. This may be because data members of
             //the derived classes must be modified by these functions or because
             //the derived class manages dynamic memory
             virtual float raise(float percentage)=0;
             virtual bool pay_period(int days_or_hours_worked) = 0;
             virtual void set_pay(float rate) = 0;
             virtual void authorize_overtime() = 0;
             virtual void authorize_benefits(char * type_of_benefits, const name & beneficiary)=0;

      protected:   
              int employee_id;
              node * root;  //for the personnel records


              void display(node * root) const;
              void copy_tree(node * & dest_root, node * source_root) const;

              
};

//There are many kinds of employees, part-time, full-time salaried, and full-time
//hourly. With OOP we can separate these into different classes. 

//The great benefit of inheritance is that the clients of the derived class
//have direct access to all of the base class' public functions!

class hourly_employee: public employee
{
      public:
             hourly_employee();
             hourly_employee(const person & input); //set up hourly emp.
             hourly_employee(int max_hours);   //set max hours 


             //ONLY HAVE FUNCTIONS HERE that have virtual prototypes in the base
             //class - otherwise the client program will have to do RTTI to use them!

             //Because these are dynamically bound in the base class, they must
             //appear in the derived class exactly in the same way, and be
             //implemented in a way that works specifically for this class
             void display() const;
             float raise(float percentage);
             bool pay_period(int hours_worked); //**Examine this in all classes
             void set_pay(float rate);
             void authorize_overtime();
             void authorize_benefits(char * type_of_benefits, const name & beneficiary);

      protected:
             int hours;
             int max_hours_allowed; //without overtime authorized
             bool overtime_ok;      //has overtime been authorized?
             float pay_rate;
};

//Supports full time employees who get benefits, but work hourly
class full_time: public hourly_employee   
{
      public:
             full_time();
             full_time(const full_time & ); //needs a copy constructor since there
                                            //dynamic memory with this class
             ~full_time();
             void display() const;
             void authorize_benefits(char * type_of_benefits, const name & beneficiary);
             //and so on
      protected:
             char * type_of_insurance;
             name beneficiary;
};

//Salaried employees (like managers) do not need hours worked,
//but they have benefits
class salaried_employee: public employee
{
      public:
             salaried_employee(); //always have one of these!
             salaried_employee(const salaried_employee &); //copy constructor
             salaried_employee(float base_salary);
             ~salaried_employee();
             //Because these are dynamically bound in the base class, they must
             //appear in the derived class exactly in the same way; for
	     //non-pure virtual functions, we could leave out the functions
             void display() const;
             float raise(float percentage);
             bool pay_period(int days_worked);
             void set_pay(float yearly_salary);
             void authorize_overtime();
             void authorize_benefits(char * type_of_benefits, const name & beneficiary);
      protected:
             char * type_of_insurance;
             name beneficiary;
             float salary;
};


