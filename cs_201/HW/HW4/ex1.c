#include <stdio.h>
#include "ex1_crypt.h"

void getpassword()
{
    printf("The password is: %lu\n ", getcrypt_ex1());
}

void ex1()
{
    char name[10];
    int value =0;

    printf("Enter your name: ");
    gets(name);
    if (value == 3223602)
    {
        getpassword();
    }
    else
    {
        printf("Welcome to CS201: %s\n", name);
    }
}

int main(int argc, char*arv[])
{
    ex1();
    return 0;
}