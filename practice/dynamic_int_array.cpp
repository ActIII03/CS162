#include <iostream>

using namespace std;

int main(void)
{
    int *p;
    p = new int[5];

    *p = 10;
    ++p;
    
    *p + 25;

    for (int i = 2; i < 5; ++i)
        p[i] = 0;

    for(int i = 0; i < 5; ++i)
        cout << "p[" << i << "] is: " << p[i] << endl;

    return 0;
}
