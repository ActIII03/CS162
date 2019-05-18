#include <iostream>

using namespace std;

int main(void)
{
    char array[11];
    int index, count;
    cin.get(array, 11, '\n');
    cin.ignore(100,'\n');

    for ( index = 0, count = 0; index < 11 ; ++index)
    {
        if ( array[index] >= 65 && array[index] <=90 )
            count++;
    }
    
    cout << array;
    cout << "Number of uppercases: " << count;

    return 0;
}
