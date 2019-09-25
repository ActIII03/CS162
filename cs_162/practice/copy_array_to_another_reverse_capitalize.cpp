#include <iostream>
#include <cstring>
#include <cctype>

const int SIZE = 25;

using namespace std;

int main(void)
{
    char array[SIZE];
    char sec_array[SIZE];

    cout << "Input a word in all lower-case: ";
    cin.get(array, SIZE, '\n');
    cin.ignore(100, '\n');

    int length = strlen(array);

    for( int index = 0, sec_index = length; index < length; ++index, --sec_index)
    {
        if( islower(array[index]))
            array[index] = toupper(array[index]);
        else if( ispunct(array[index]) )
            array[index] = ' ';
        sec_array[sec_index] = array[index];
    }
    cout << array << '\n' << sec_array << '\n' << endl;
    return 0;

}
