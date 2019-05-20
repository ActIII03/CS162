#include <iostream>
using namespace std;

const double PI = 3.1416;

int main()
{
     double *radius_pntr;

     radius_pntr = new double;

     cout << "Enter radius*: ";
     cin >> *radius_pntr;
     cout << endl;

     cout << "Radius*: " << *radius_pntr
          << "\narea = " << PI * (*radius_pntr) * (*radius_pntr)
          << endl;

     cout << "Address of radius*: " << &radius_pntr
          << "\nValue held: " << radius_pntr
          << "Value stored in radius_pntr: " << *radius_pntr
          << endl;

     delete radius_pntr;

