#include <iostream>
using namespace std;

int main()
{
    char ch;
    cin >> ch;
    cin.ignore(100 , 'A');
    cout << "\n" << ch;
    return 0;
}
