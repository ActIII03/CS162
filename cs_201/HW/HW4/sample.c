#include <stdio.h>
#include <stdlib.h>
#include "sample_crypt.h"

void getpassword()
{
    printf("The password is: %lu\n ", getcrypt_sample());
}

void sample(long value)
{
    if (value == 1)
    {
        getpassword();
    }
    else
    {
        printf("Hint: Select option 1 to see password\n");
    }
}

int main(int argc, char*arv[])
{
    char option[2];
    long value=0;
    
    printf("Enter option: ");
    fgets(option, 2, stdin);
    value= strtol(option, NULL, 10);
 
    sample(value);
    return 0;
}
