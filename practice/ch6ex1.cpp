#include <iostream>

using namespace std;

int product( int x, int y);

int main ()
{
    int x = 4, y =2;
    int prod = product( x , y);
    cout << prod;
    return 0;
}

int product( int x ,int y )
{
    return x * y;
}
