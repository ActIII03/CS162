#include <stdio.h>

int main()
{
    int weight = 0, height = 0, result = 0;

    printf("Please enter your weight and height\nWeight (lbs): ");
    scanf("%d", &weight); 
    printf("\nHeight (in): ");
    scanf("%d", &height); 
    result = ( weight * 703 ) / (height * height);

    printf("Result: %d", result, "\n");
    return 0;
}
