#include <iostream>

using namespace std;

int main(void)
{
    int first_value, second_value;
    int *pntr;
    pntr = &first_value;
    *pntr = 10;
    pntr = &second_value;
    *pntr = 20;

    cout << "First value: " << first_value << endl;
    cout << "Second value: " << second_value << endl;
    return 0;
}
