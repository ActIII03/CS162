#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

long fibonacci(long n);

int main(void)
{
    int n = 0;

    printf("Please input an integer (n) to get the nth sequence of the fibonacci:\n");
    scanf("%d", &n);

    printf("Sequence:\n%ld\n", fibonacci(n));

    return 0;
}
