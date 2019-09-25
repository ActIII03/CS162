#include <iostream>

using namespace std;

int pass_by_value(int x);
int pass_by_ref(int & x);

int main()
{
    int x = 10;

    cout << x << endl;
    cout << pass_by_value(x) << endl;
    cout << x << endl;
    cout << pass_by_ref(x) << endl;
    cout << x << endl;
    return 0;
}

int pass_by_value(int x )
{
    x = 15;
    return x;
}
int pass_by_ref(int & x)
{
    x = 25;
    return x;
}
