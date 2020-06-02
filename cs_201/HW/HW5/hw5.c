#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

long fibonacci(long n);

int main(void)
{
    int n = 10;

    printf("Sequence:\n%ld\n", fibonacci(n));

    return 0;
}
