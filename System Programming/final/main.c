#include <stdio.h>

long convertBinary(char* a, long start, long end)
{
    if(start > end)
        return 0;
    if(a[end] == 48)
        return (convertBinary(a, start, end - 1) << 1);
    else
        return (convertBinary(a, start, end - 1) << 1) | 1;
}

void main(void){

    char integer[:wq
}
