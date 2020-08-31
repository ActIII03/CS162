#include "outer.h"

int main()
{
    int N = 4;
    
    ARR my_ARR(N);
    BST_arr B_arr(N);

    /* Time function can be used to time the execution
     * of any function. Use example:
     * unsigned int sum = 0;
     * time_function(&ARR::actual_sum, sum, my_ARR);
     * cout << "ARR actual sum: " << sum << endl;
     * */

    unsigned int sum = 0;
    time_function(&ARR::actual_sum, sum, my_ARR);
    cout << "ARR actual sum: " << sum << endl;
    time_function(&BST_arr::actual_sum, sum, B_arr);
    cout << "B_arr actual sum: " << sum << endl;
    unsigned int max = 0;
    time_function(&ARR::actual_max, max, my_ARR);
    cout << "ARR actual max: " << max << endl;
    time_function(&BST_arr::actual_max, max, B_arr);
    cout << "B_arr actual max: " << max << endl;
    //my_ARR.display();
    //B_arr.display();

    return 0;
}
