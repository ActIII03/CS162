#include <iostream>

using namespace std;


int main(void)
{
    int num_array[5] = {10,10,15,15,20};
    int sum = 0, index;

    cout << "Input ten non-negative integers: ";
    //cin.get(num_array, SIZE, '\n'); <--- Why doesn't this work? 
    for ( index = 0 ; index < 5 ; ++index)
    {
        sum += num_array[index];
    }
    cout << "Sum of array is: " << sum << endl;

    for (index = 0; index < 5; ++index)
        cout << num_array[index] << endl;

    return 0;
}
