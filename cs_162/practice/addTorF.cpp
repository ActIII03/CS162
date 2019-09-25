#include <iostream>
using namespace  std;

int main(void)
{
    int a=0, b=0, sum=0;

    cin >> a >> b;
    sum+=(a+b);

    if(sum > 0)
        cout << "True, sum is > 0";
    else
        cout << "False, sum is < 0";
    return 0;
}
