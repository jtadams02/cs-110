#include <stdio.h>
#include <math.h>
#define STRING_PER_CAN 400

int main(void) {
    double dist;
    printf("How far is your hometown from campus: ");
    scanf("%lf",&dist);

   // printf("Your hometown is %.2lf miles away",dist);
    int cansToMiles = ceil(dist/((double) STRING_PER_CAN/5280));

    printf("You would need %d cans of silly string to cover %.1lf miles from campus to your hometown!",cansToMiles,dist);

}