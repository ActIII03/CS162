#include <iostream>

using namespace std;

int main(void)
{
    int num_array[10];
    int largest_num, index;

    cout << "Input integers: ";

    for ( index = 0; index < 10 ; ++index )
    {
        cin >> num_array[index];
        if ( num_array[index] > largest_num )
            largest_num = num_array[index];
    }

    cout << "Largest number is: " << largest_num;
    return 0;
}
