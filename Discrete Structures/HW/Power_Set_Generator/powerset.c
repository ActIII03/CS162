#include "powerset.h"

void greet_user()
{
    printf("This program will generate the Powerset for any given a set.\n"
            "Two things needed from you:\n"
            "(1) Cardinality of the set (Non-negative integer)\n"
            "(2) Elements in your set (Letters ONLY)\n");
}

char * read_in_set(int * set_size)
{
    int index;
    char * set;

    //Get size of set from user
    printf("How many element are in the set?: ");
    scanf("%d",set_size);

    //Dynmaically allocate array
    set = (char*) malloc(sizeof(char) * (*set_size));
    
    //Readin from user
    for(index = 0;  index < (*set_size); ++index)
    {
        printf("Element (%d): ", (index + 1));
        scanf("%s",&set[index]);
    }

    set[index] = '\0';

    return set;
}

void printPowerSet(char *set, int set_size) 
{ 
    /*set_size of power set of a set with set_size 
      n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size); 
    int counter, j = 0; 
  
    printf("Resulting Powerset:\n");

    for(counter = 0; counter < pow_set_size; counter++) 
    { 
        printf("set(%d) ", counter + 1);
        
        //Find binary relation w/ Recursion
        binary_relation(&j, counter, set_size, set);

        printf("\n");

    } 
} 

void binary_relation(int * jth_element, int bin_counter, int set_size, char *set)
{
    if( (*jth_element) == bin_counter)
    {
        *jth_element = 0;
        return;
    }
    else if(bin_counter &  1 << (*jth_element) )
        printf(" %c ", set[*jth_element]);

    ++(*jth_element);

    //Tail recursion
    binary_relation( jth_element, bin_counter, set_size, set);

    return;

}

