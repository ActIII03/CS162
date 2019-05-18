#include <iostream>
#include <cctype>
#include <cstring>

const int SIZE = 100;

using namespace std;


void capital_letters(char c_letter[]);
void vowel_letters(char v_letter[]); 
void spaces(char c_letter[]);
void every_other_char(char o_letter[]);
void hi(char c_ltter[]);

int main()
{
    char char_array[SIZE];
    cin.get(char_array, SIZE, '\n');
    cin.ignore(100,'\n');
    
    int char_count = strlen(char_array);
    cout << "There is this " << char_count << " many char characters in this present array." <<endl;

    capital_letters(char_array);
    vowel_letters(char_array);
    spaces(char_array);
    every_other_char(char_array);
    hi(char_array);
    return 0;
}

void capital_letters(char c_letter[])
{
    int str_length = strlen(c_letter);
    int c_count = 0;

    for (int index = 0; index < str_length - 1; ++index)
    {
        if (isupper(c_letter[index]))
            ++c_count;
    }

    cout << "There are " << c_count << " capitalized letters in the sentence. " << endl;
}

void vowel_letters(char v_letter[])
{
    char vowel_array[11] = {'A','E','I','O','U','a','e','i','o','u'};
    int str_length = strlen(v_letter);
    int v_count = 0;

    for (int index = 0; index < str_length - 1; ++index)
    {
        for (int v_index = 0; v_index < 11; ++v_index)
        {
            if(v_letter[index] == vowel_array[v_index])
                ++v_count;
        }
    }

    cout << "There are " << v_count << "  vowels in the sentence. " << endl;
}

void spaces(char c_letter[])
{
    int str_length = strlen(c_letter);
    int s_count = 0;

    for (int index = 0; index < str_length - 1; ++index)
    {
        if (isspace(c_letter[index]))
            ++s_count;
    }

    cout << "There are " << s_count << " space in the sentence. " << endl;
}


void every_other_char(char o_letter[])
{
    char copy_array[SIZE];
    strcpy(copy_array, o_letter);
    int str_length = strlen(copy_array);
    bool flag = false;

    for(int index = 0; index < str_length ; ++index)
    {
        if(flag == true)
        {
            if(o_letter[index] == ' ')
                flag = true;
            else
            {
                copy_array[index] = '_';
                flag = false;
            }
        }
        else if( flag == false)
            flag = true;
    }

    cout << "Here is the sentence with every other letter displayed\n\n"
         << copy_array << endl;
}

void hi(char c_letter[]) 
{
    char hi[] = {'h','i'};
    int str_length = strlen(c_letter);
    int hi_count = 0;
    
    for(int index = 0; index < str_length - 1; ++index)
    {
        if(c_letter[index] == hi[0] && c_letter[index+1] == hi[1])
            ++hi_count;
        else if(c_letter[index] == toupper(hi[0]) && c_letter[index+1] == toupper(hi[1]))
            ++hi_count;
    }

    cout << "Hi appeared " << hi_count << " times." << endl;
}
