#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    char buffer[250];
    cin.get(buffer, 250);
    cin.ignore();
    cout << "Buffer: " << buffer << endl;
    return 0;
}
