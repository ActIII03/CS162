#include "store.h"
using namespace std;
using namespace collection;

const int MAX = 100;

//This code is to test out the hierarchy of the clases created
int main()
{
    char temp[MAX];
    char response;
    
    //experiment with the hourly employee class
    store kohls;
    
    do
    {
       hourly_employee new_hire;
       person person_applying;
       cout <<"What is the name of the person applying for a job\n";
       person_applying.read();
       cout <<"\nWe received information about this person:\n";
       person_applying.display();
    
       cout <<"\nWould you like to hire them? Y or N ";
       cin >>response; cin.ignore(100,'\n');
       if (toupper(response) == 'Y')
       {
          new_hire.hire(person_applying);
          
          do
          {        
              cout <<"\nPlease enter their periodic performance review: ";
              cin.get(temp, MAX,'\n'); 
              cin.ignore(MAX, '\n');

              new_hire.performance_review(temp);
              cout <<"\nIs there another review? Y/N ";
          } while (again());

          kohls.add(new_hire);  //this will add the person to the binary search tree!
       }
       cout <<"\nIs there another employee? Y/N ";
    } while (again());

    cout <<"\n\n*********The current list of hourly employees is:\n";
    kohls.display_all();

/*
//UNCOMMENT OUT THIS CODE ONCE YOU HAVE IMPLEMENTED THE COPY CONSTRUCTOR FOR THE BINARY TREE CLASS 
    //Now test out your copy constructor code
    store cs_department_store(kohls);   //Put the code here to test out your copy constructor
    cout <<"\n\nHere is the copy: \n";
    cs_department_store.display_all();
*/    
    
    return 0;
}
