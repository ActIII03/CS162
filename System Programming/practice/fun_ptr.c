#include <stdio.h>

void print_even(int i){printf("Even: %d\n", i);}
void print_odd(int i){printf("Odd: %d\n", i);}

int main(int argc, char * argv[])
{
    void (*fp)(int);

    fp = (argc % 2 == 0) ? print_even : print_odd;
    fp(argc);
    return 0;
}
