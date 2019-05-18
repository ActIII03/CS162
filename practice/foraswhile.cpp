#include <iostream>

using namespace std;

int main(void)
{
    int i=0,j=0;

    while( i <= 10)
    {
        while( j <= i)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        ++i;
    }
    return 0;
}
