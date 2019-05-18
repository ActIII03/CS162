#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    int num_array[10] = {1,3,5,7,11,13,17,19,23,29};
    //int *int_pntr_array = &num_array;
    int *int_pntr_array;
    int_pntr_array = num_array;  //Why is this legal?

    for (int i = 0; i < 10; ++i)
        cout << "Value: " <<  *(int_pntr_array + i) << endl;

    
    for (int i = 0; i < 10; ++i)
        cout << "Address: " <<  int_pntr_array + i << endl;
    return 0;
}
