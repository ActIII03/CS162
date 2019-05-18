#include <iostream>

using namespace std;


int main(void)
{
    int num_array[11];
    int sum = 0, index;

    cout << "Input ten non-negative integers: ";
    //cin.get(num_array, SIZE, '\n'); <--- Why doesn't this work? 
    for ( index = 0 ; index < 10 ; ++index)
    {
        cin >> num_array[index];
        sum += num_array[index];
    }
    cout << "Sum of array is: " << sum;

    return 0;
}
