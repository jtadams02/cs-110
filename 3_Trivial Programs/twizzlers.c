/*
*
*
*
*
/
*/

#include <stdio.h>
#include <math.h>
#define TWIZZLERS_PER_PACK 25
#define FEET_PER_MILE 5280
#define INCHES_PER_FOOT 12
int main() {
    const double twizzlerLength = 7.0;
    double dist = 0;

    printf("What is the distance between City A and City B?: ");
    scanf("%lf",&dist);

    printf("Your distance is: %.2lf\n",dist);

    double inches = dist * FEET_PER_MILE * INCHES_PER_FOOT;

    int packsOfTwizzlers = ceil(inches / (twizzlerLength*TWIZZLERS_PER_PACK));

    printf("You will need %d packs of twizlers to cover %.2lf miles.\n",packsOfTwizzlers,dist);


    
    return 0;
}