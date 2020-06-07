#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


//Here is an example of a constant; constants should
//be global so that they are accessible by all functions
//and there are no "side effects" unlike with global
//variables (which should be avoided!)
const int F_NAME = 22;
const int MAJOR = 17;

int main()
{
    //Place your code here:
    char full_name[F_NAME];
    char major[MAJOR];
    char buffer[100];
    int strlength;

    cout << "Please enter your full name: ";
    cin.get(full_name, F_NAME, '\n');
    full_name[0] = toupper(full_name[0]); // Capitalize first char character
    cin.ignore(100, '\n');

    for (int i = 0 ; i < F_NAME ; ++i)
    {
        if ( full_name[i] == ' ' )
            full_name[i+1] = toupper(full_name[i+1]);
    }

    do
    {
        cout << "Please enter your major: ";
        cin.get(major, MAJOR, '\n');
        cin.get(buffer, 100, '\n');
        cin.ignore(100, '\n');
        strlength = strlen(buffer);
        if ( strlength > 0 )
        {
            cout << " You enter too much for your major!" << endl;
            cout << "Re-enter your major" << endl;
        }
    }
    while ( strlength > 0 );


    cout << "Name: " << full_name << endl;
    cout << "Major: " << major << endl;
    
    return 0;
}
