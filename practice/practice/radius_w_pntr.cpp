#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.1416;

int main()
{
    double radius;
    double *radius_pntr;

    cout << fixed << showpoint << setprecision(2);

    radius = 2.5;
    radius_pntr = &radius;

    cout << "Line 19: radius is  " << radius
         << "\n area = " << PI * radius * radius << endl;

    cout << "Line 22: radius pointer " << *radius_pntr
         << "\n area using pointer = " << PI * (*radius_pntr) * (*radius_pntr) << endl;

    cout << "Enter a radius into the pointer radius: ";
    cin >> *radius_pntr;

    cout << "Line 28: radius " << radius
         << "\n area = " << PI * radius * radius << endl;

    cout << "Line 31: radius pointer " << *radius_pntr
         << "\n area using pointer = " << PI * (*radius_pntr) * (*radius_pntr) << endl;

    cout << "Address of radius_pntr: " << &radius_pntr << endl;
    cout << "Value stored in radius_pntr: " << radius_pntr << endl;
    cout << "Address of radius: " << &radius << endl;
    cout << "Value stored in radius: " << radius << endl;

    return 0;

}
