#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string car;
    int year;

    cout << "Please enter your car and year of that car: ";
    cin >> car >> year;
    cout << "Car: " << car << "\nYear: " << year;

    cin.clear();
    cin.ignore(200 , '\n');

    cout << "\nPlease enter your car and year of that car: ";
    cin >> car >> year;
    cout << "Car: " << car << "\nYear: " << year;

    return 0;
}

