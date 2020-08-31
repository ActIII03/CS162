#pragma once
#include <iostream>
#include <fstream>
#include "omp.h"
#include "stdlib.h"
#include <unistd.h>
#include <iomanip>
#include <sys/time.h>
#if(_cplusplus != 199711L)  // checks to make sure that c++ version is not c++98
#include <functional>
#endif
using namespace std;
const long SIZE = 250000;

int fill_array(int array[]);

// The below 2 functions, convert_timeval and time_function,
// use c++11 features to allow you to time the execution of
// a function. Don't use templates, m_func or ... in your 
// code, as we will compile your programs using c++98.

#if(_cplusplus != 199711L)  // checks to make sure that c++ version is not c++98
double convert_timeval(struct timeval start, struct timeval end);

/* Below function calls a given class member function
 * on a given instance of the class, printing the amount
 * of time the function took to execute, in seconds.
 *
 * Use example: 
 * ARR my_arr
 *
 * unsigned int sum = 0;
 * time_function(&ARR::sum_all, sum, my_arr);
 * cout << "Total: " << sum << endl;
 *
 * @param func - Pointer to member function to call. Remember &
 *  before scope resolution operator.
 * @param ret - Store return value here by reference
 * @param context - Instance of object to call func on
 * @param args - Variable number of arguments to pass to func
 * */
template <class T, class A, class C, class... Args>
void time_function(T (func), A & ret, C & context, Args... args)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    auto m_func = mem_fn(func);
    ret = m_func(context, args...);
    gettimeofday(&end, NULL);
    cout << fixed << setprecision(3) << convert_timeval(start, end) << 's' << endl;
}
#endif
