#include <stdio.h>

#define CUP_COST 5
#define CANDY_COST 30
#define POPCORN_COST 20
#define WATER_COST 50

#define START_CUP 2000
#define START_CANDY 1000
#define START_POPCORN 2500
#define START_WATER 750

int main(void) {
    int cups,candy,popcorn,water;

    printf("Enter the number of cups, candy, popcorn, and water remaining:\n");
    scanf("%d %d %d %d",&cups,&candy,&popcorn,&water);

   // printf("You have: %d cups, %d candy, %d popcorn, and %d water!",cups,candy,popcorn,water);
    printf("Need: %d cups, %d candy bars, %d bags of popcorn, and %d bottles of water\n",(START_CUP - cups),(START_CANDY-candy),(START_POPCORN-popcorn),(START_WATER-water));

    int totalCost = ((START_CUP - cups)*CUP_COST)+((START_CANDY-candy)*CANDY_COST)+((START_POPCORN-popcorn)*POPCORN_COST)+((START_WATER-water)*WATER_COST);
    int dollar = totalCost/100;
    int cent = totalCost%100;
    printf("Cost: %d dollars and %d cents\n",dollar,cent);

    double avgCup = ((double)(START_CUP-cups)/7);
    double avgCandy = ((double)(START_CANDY-candy)/7);
    double avgPop = ((double)(START_POPCORN-popcorn)/7);
    double avgW = ((double)(START_WATER-water)/7);

    printf("Average sold: %.2lf cups, %.2lf candy bars, %.2lf bags of popcorn, and %.2lf bottles of water per day",avgCup,avgCandy,avgPop,avgW);




    return 0;
}