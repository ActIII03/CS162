#include <iostream>

using namespace std;

int main(void)
{
    int i = 1, count = 0;
    int odd_array[101];
    while(count < 100)
    {
        odd_array[count] = i;
        i+=2;
        ++count;
    }
    for ( int index = 0; index < 101 ; ++index )
        cout << "Array of odd numbers:'\n'" << odd_array[index] << endl;
    return 0;
}
