#include <iostream>
#include <fstream>

using namespace std; 

const int SIZE = 20;
const int BIO = 100;
const int DESC = 140;
const int MAX = 10;

struct hero_type
{
    char name[SIZE];
    char identity[SIZE];
    char power[SIZE];
    char lover[SIZE];
    char origin[BIO];
    char opinion[DESC];
};

int main()
{
    ifstream in_file;
    hero_type n_h;

    int times = 0;

    in_file.open("super_heros.txt");
    if(in_file)
    {
        in_file.getline(n_h.name, SIZE, ':');
        in_file.ignore(100,'\n');

        in_file.getline(n_h.identity, SIZE, ':');
        in_file.ignore(100,'\n');
        while(in_file && !in_file.eof() && times < 1)
        {
            cout << n_h.name << '\n' << n_h.identity;
            ++times;
        }
        in_file.close();
        in_file.clear();
    }

    return 0;
}
