#include <iostream>
#include <cmath>

using namespace std;


int main(void)
{
    int num_array[11];
    int index;

    cout << "Input ten non-negative integers: ";
    //cin.get(num_array, SIZE, '\n'); <--- Why doesn't this work? 
    for ( index = 0 ; index < 10 ; ++index)
    {
        cin >> num_array[index];
    }

    for ( index = 0; index < 10 ; ++index)
        cout << "\n" << pow(num_array[index],2) << endl;

    return 0;
}
