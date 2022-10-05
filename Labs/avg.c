/*
*   JT Adams
*   08/26/2021
*
*   ----------
*   Lab #1
*/

#include <stdio.h>

int main(){
    int one;
    int two;
    int three;
    int four;

    printf("Enter four intergers:\n");
    scanf("%d %d %d %d",&one,&two,&three,&four);
    double avg = ((double)(one+two+three+four)/4);
    //printf("\nYour numbers are: %d, %d, %d, and %d",one,two,three,four);

    printf("The average is %lf",avg);

    return 0;
}