#include <iostream>
#include <cctype>

using namespace std;

bool is_char_vowel(char vowels); 
const int SIZE = 21;

int main(void)
{
    char char_array[SIZE];
    char result[SIZE];
    int index, word_length;

    cout << "Please enter a word: ";
    cin.get(char_array, 20, '\n');

    word_length = strlen(char_array);

    for ( index = 0; index < word_length; ++index )
    {
        if ( is_char_vowel(char_array[index]) )
            result[index] = char_array[index];
        else if ( char_array[index] == ' ' )
            result[index] = ' ';
        else
            result[index] = '_';
    }

    cout << "Here is your word with juat vowels and underscores where there weren't any vowels: " << result;

    return 0;
}

bool is_char_vowel(char vowels)
{
    char vowel_array[6] = {'a','e','i','o','u'};
    for ( int index = 0; index < 6; ++index )
    {
        if ( vowels == vowel_array[index])
                return true;
    }
    return 0;
}

