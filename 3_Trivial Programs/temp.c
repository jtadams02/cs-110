/*
*
*
*
*
*
*/

#include <stdio.h>

int main() {
    double input = 0;
    printf("Enter Fahrenheit Temperature: ");
    scanf("%lf",&input);

    printf("\nYour temperature in F is: %lf",input);

    double output = ((input-32) *(5/9));

    printf("\n%lf degrees F is equal to %lf in degrees Celcius",input,output);



    return 0;
}