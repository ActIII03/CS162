#include <iostream>
#include <cctype>
#include <cstring>

const int SIZE = 50;

using namespace std;

int main()
{
    char char_array[SIZE];
    //char vowel_array[11] = {'A','E','I','O','U','a','e','i','o','u');
    cin.get(char_array, SIZE, '\n');
    cin.ignore(100,'\n');

    int str_length=strlen(char_array);

    for (int index = 0, counter = 0; index < str_length -1 ; ++index, ++counter)
    {
        if (isupper(char_array[index]))
            ++counter;
    }

    cout << "There are " << counter << "capitalized letters in the sentence. " << endl;

    return 0;
}
