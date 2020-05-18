#include <stdio.h>
#include <stdlib.h>
#include "ex2_crypt.h"

void getpassword()
{
    printf("The password is: %lu\n ", getcrypt_ex2());
}

void ex2()
{
    char phonestr[11];
    long value=0;
    
    printf("Enter phone number: ");
    fgets(phonestr, 11, stdin);
    value= strtol(phonestr, NULL, 10);

    if (value == sum)
    {
        getpassword();
    }
    else
    {
        printf("Incorrect Phone Number %lu\n", value);
    }
}

int main(int argc, char*arv[])
{
    ex2();
    return 0;
}