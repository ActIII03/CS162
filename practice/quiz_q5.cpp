#include <iostream>

using namespace std;

int main(void)
{
    for(int i = 0; i <2 ; ++i)
        for(int j = i; j < 2 ; j++)
            cout << i << " " << j << endl;

    return 0;
}
