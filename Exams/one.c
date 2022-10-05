#include <stdio.h>
#include <string.h>

/*
- less than 500 sq. ft.
   - "new-york" style = 1 year
   - "cave" and "shack" styles = 2 years
   - other styles = 3 years
- between 500 and 1500 sq. ft. (including 500 and 1500)
   - "future" style = 4 years
   - "cajun" style = 5 years
   - other styles = 6 years
- greater than 1500 sq. ft., regardless of style = 7 years
*/

#define NY_STYLE 1
#define CAVE_SHACK_STYLE 2
#define OTHER_STYLES 3

#define FUTURE_STYLE 4
#define CAJUN_STYLE 5
#define OTHER_STYLE_2 6

#define LARGER_STYLES 7
int main() {


    int sqft = 0;
    char style[20];
    char end[] = "Estimated years to build: ";

    printf("Enter the square footage: ");
    scanf("%d",&sqft);
    printf("\n");

    printf("Enter the style: ");
    scanf("%s",style);
    printf("\n");
    //Selection branch for SQFT <500
    if(sqft<500)
    {
        if(strcmp(style,"new-york")==0)
        {
            printf("%s%d",end,NY_STYLE);
        } else if((strcmp(style,"cave")==0)||(strcmp(style,"shack")==0))
        {
            printf("%s%d",end,CAVE_SHACK_STYLE);
        } else {
            printf("%s%d",end,OTHER_STYLES);
        }
        
    }

    //Selection branch for 500<SQFT<1500
    if(sqft>=500&&sqft<=1500)
    {
        if(strcmp(style,"future")==0)
        {
            printf("%s%d",end,FUTURE_STYLE);
        } else if(strcmp(style,"cajun")==0)
        {
            printf("%s%d",end,CAJUN_STYLE);
        } else {
            printf("%s%d",end,OTHER_STYLE_2);
        }
    }

    //Selection branch for SQFT>1500
    if(sqft>1500)
    {
        printf("%s%d",end,LARGER_STYLES);
    }
   
   
   return 0;
}
