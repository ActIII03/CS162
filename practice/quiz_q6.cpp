#include <iostream>

using namespace std;

int main(void)
{
    char c;
    cin >> c;
    for ( ; c != 'n'; cin >> c)
    {
        cout << "Do you want to continue looping?" << endl;
    }
    return 0;
}
