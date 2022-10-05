/*
*   JT Adams
*   08/26/2021
*
*   ----------
*   Lab #2
*/

#include <stdio.h>
#include <math.h>

int main(){
    int startHour;
    int startMin;
    int endHour;
    int endMin;

    printf("Enter the start time: ");
    scanf("%d %d",&startHour,&startMin);

    printf("Enter the end time: ");
    scanf("%d %d",&endHour,&endMin);
    /*
    double milesMin = (double)((abs(startMin-endMin)/60)*4);
    double miles = (abs(startHour-endHour)*4);
    double final = miles+milesMin;
    */
    double start = (startHour+((double)startMin/60));
    double end = (endHour+((double)endMin/60));

   // printf("Started: %lf , and ended: %lf",start,end);
    
    double time = (fabs(end-start));

    double final = (time*4);


    printf("You have walked %lf miles",final);
    

    return 0;
}