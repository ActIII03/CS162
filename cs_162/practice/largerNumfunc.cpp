#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;

double larger(double x, double y);
double compareThree(double x, double y, double z);

int main()
{
    double one = 10, two = 20, three = 30;
    
    cout << "The larger of 15 and 25 is: " << larger(15, 25) << endl;
    cout << "The larger of " << one << " and " << two << " is: "
        << larger(one, two) << endl;
    cout << "The larger of " << one << " and 29 is: " << larger(one, 29)
        << endl;
    cout << "The largerest of " << one << ", " << two << ", and " << three
         << " is: " << compareThree( one, two, three) << endl;
    return 0;
}

double larger (double x, double y)
{
    double max;

    if (x >= y)
        max = x;
    else
        max = y;
    return max;
}

double compareThree(double x, double y, double z)
{
    return larger( x, larger(y, z));
}
