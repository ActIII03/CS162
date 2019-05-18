#include <iostream>

using namespace std;

int const SIZE = 10;

int main(void)
{
    int index, largestNum = 0;
    int array[SIZE] = { 1,9,2,3,8,4,5,6,7 };
    for ( index = 0; index < 10 ; ++index)
    {
        if ( largestNum < array[index] )
            largestNum = array[index];
    }
    cout << largestNum;
    return 0;
}
