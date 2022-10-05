#include <stdio.h>

int main(void)
{
    int hours;
    double wage;
    int overtime;
    int doubletime;
    double pay;
    printf("Enter your wage and your hours this week: ");
    scanf("%lf %d",&wage,&hours);
    
    if(hours<=40)
    {
        pay = (hours*wage);
    } else if(hours>40&&hours<=50)
    {
        pay = (40*wage)+((hours-40)*(1.5*wage));
    } else if(hours>50)
    {
        pay = ((double)40*wage)+((double)(1.5*wage)*10)+((double)(hours-50)*(2*wage));
    }

    printf("%lf",pay);





    return 0;
}