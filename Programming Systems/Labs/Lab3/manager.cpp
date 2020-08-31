#include "manager.h"
using namespace std;


//Step 8a - Finish the manager constructor
//
//FINISH THIS FUNCTION.
//HINT - it needs an initialization list to set up the
//managers information
manager::manager( const salaried_employee & managers_information) 
 {
    cout <<"\nPlease enter the group name: ";
    group_name.read();
    cout <<"\nHow many group_members? ";
    cin >> num_employees; cin.ignore(100,'\n');

    //COMPLETE THIS FUNCTION - allocating the dynamic array of
    //employees in this group:


}

//Step 8b - Implement the manager destructor
//
//Deallocate the array of employee pointers
manager::~manager()
{
}

// *********** STOP ************* 
// now you will be workiing on experiencing dynamic binding by
// modifying main. Read the lab manual for Step 9

//Step 10 - Experiencing RTTI
//
//THIS FUNCTION REQUIRES RTTI!!!
void manager::add_to_group( const employee & to_add)
{

}

//SAMPLE
void manager::display() const
{
    cout <<"MANAGER ";
    salaried_employee::display();
    cout <<"\nGROUP NAME: ";
    group_name.display();
    for (int i = 0; i < num_employees; ++i)
      if (group[i]) group[i]->display();
}   
