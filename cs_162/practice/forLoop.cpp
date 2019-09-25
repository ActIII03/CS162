#include <iostream>

using namespace std;

int main(void)
{
    for ( int j = 0 ; j <= 10; ++j)
    {
        for (int i = 1; i <= j; i++)
                cout << "*";
        cout << "\n";
    }
    return 0;
}
