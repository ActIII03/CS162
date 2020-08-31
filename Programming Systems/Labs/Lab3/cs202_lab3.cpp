#include "manager.h"
using namespace std;

const int MAX = 100;
const int MAX_EMPLOYEES = 10;

//This code is to test out dynamic binding for different kinds of employees
int main()
{
    char temp[MAX];
    char response;
    person person_applying;
    name for_insurance;
    float rate;
    
    //experiment with dynamic binding
    employee * all_employees[MAX_EMPLOYEES]; //this can point to any kind of employee
    int num_employees=0;          //keep track of the number of employees
    int i = 0;
    
    do
    {
       cout <<"What is the name of the person applying for a job\n";
       person_applying.read();
       cout <<"\nWe received information about this person:\n";
       person_applying.display();
    
       cout <<"\nAre they part-time hourly (P), full-time hourly (F), or salaried (S)? ";
       cin >>response; cin.ignore(100,'\n');
       cout <<"\nWhat is the hour rate or salary: ";
       cin >>rate;  cin.ignore(100,'\n');
       response = toupper(response);
       switch (response)
       {
 
          case 'P': all_employees[i] = new hourly_employee;
                    break;
          case 'F': all_employees[i] = new full_time;
                    cout <<"Please provide the name of your beneficiary: ";
                    for_insurance.read();
                    break;
          case 'S': all_employees[i] = new salaried_employee;
                    cout <<"Please provide the name of your beneficiary: ";
                    for_insurance.read();
                    break;
          default: cout <<"We will assume...hourly part time!\n";
                    all_employees[i] = new hourly_employee;
        }
        all_employees[i]->hire(person_applying);
        all_employees[i]->set_pay(rate);
        all_employees[i]->authorize_benefits((char*)"PEBB",for_insurance);

        do
        {
              cout <<"\nPlease enter their periodic performance review: ";
              cin.get(temp, MAX,'\n');
              cin.ignore(MAX, '\n');

              all_employees[i]->performance_review(temp);
              cout <<"\nIs there another review? Y/N ";
        } while (again());

        cerr <<"\n\nThis is the complete information about the new hire... \n";
        all_employees[i]->display();

        if (i++ < MAX_EMPLOYEES)
           cout << "\nIs there another employee? Y/N ";
    } while (i < MAX_EMPLOYEES && again());
    
    num_employees = i;
    cout <<"\n\nThe current list of hourly employees is:\n";


    for (int i = 0; i < num_employees; ++i)
    {
        all_employees[i]->display();
        cout <<endl;
    }

    //Now deallocate all - is the correct destructor being used?
    for (int i = 0; i < num_employees; ++i)
    {
        delete all_employees[i];
    }
    return 0;
}
