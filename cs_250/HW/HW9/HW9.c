#include "powerset.h"

/*Driver program to test printPowerSet*/
int main() 
{ 
    int set_size = 0;

    //Greet user
    greet_user();

    //Read-in from user a set dynamically
    char * set = read_in_set(&set_size);
    
    //Generate Powerset
    printPowerSet(set, set_size); 

    //De-allocate set
    free(set);

    return 0; 
} 

