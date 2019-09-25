#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{

    char array[18] = { 'h','e','l','l','o'};
    char *ptr = array;

    cout << "a: " << *ptr
         << "\nb: " << ptr
         << "\nc: " << *(ptr+2)
         << "\nd: " << (ptr + 2)
         << "\ne: " << *(ptr+strlen(ptr) - 1);
    return 0;
}
