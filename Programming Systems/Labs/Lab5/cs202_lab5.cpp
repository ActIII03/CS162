#include "store.h"
using namespace std;

//Implement each of these using exception handeling
//For each function consider if you should have the try block
//in the function or if you should have the try block in the
//calling routine. If you throw an exception without a
//try block, then add an exception specification list

// step (1): Reasons for exception handling:
// (i) integer length longer than expected
// (ii) when number contains non-numeric values
// (iii) character character/array contains numeric values
// (iv) Empty field
// (v) Exceed buffer size
//
// step (2): Use for structures for exception handling. 
// Description: Structures provide a mnemonic names corresponding with errors thrown. Provides a use way to rember.
//
// step (3): List functions from previous labs that may encounter errors where exception handling may come useful.

//Step 5a - throw an exception if there is an invalid response
bool again()
{
    //char response;
    //cout << " Please enter a response (Y/N): ";
    //cin >> response;
    //cin.ignore(100, '\n'(;

    try{

        char response;
        bool error = false;
        cout << " Please enter a response (Y/N): ";
        cin >> response;
        cin.ignore(100, '\n');
        if( toupper(response) != 'Y' && toupper(response) != 'N')
            throw(error);
        
    }
}

//Step 5b - implement the address constructor and throw an
//exception if ther eis a null string being copied:

address::address(char * new_street, char * new_zip)
{
}

//Step 5c - implement the set pay function and throw an
//exception if a zzero or negative pay is requested

void hourly_employee::set_pay_rate(float rate)
{
}

// *************************** Now move to main.cpp and work there


//Step 7 - implement the two compare functions. The first
//compares the employees name. Throw an exception if there is no match
bool employee::compare(const name & match)
{

}

//Now travere the binary search tree of reviews and
//throw an exception if there is no match
bool employee::compare(char * match)
{

}

