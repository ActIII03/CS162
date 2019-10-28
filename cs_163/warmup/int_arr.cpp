#include <iostream>

using namespace std;

int main(void)
{

    int num_arr[5] = { 20, 40, 60, 80, 100};

    for(int index = 0; index < 5; ++index)
    {
        cout << "Number: " << num_arr[index] << " Index: " << index << endl;
    }

    return 0;
}
