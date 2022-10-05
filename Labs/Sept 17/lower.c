#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){

    char one[50];
    char two[50];

    int oneLowerLen =0;
    int twoLowerLen=0;

    printf("Enter two strings:\n");
    scanf("%s %s",one,two);

   // printf("%s %s",one,two);
    for(int i=0;i<strlen(one);i++)
    {
        if(islower(one[i]))
        {
            oneLowerLen++;

        }

    }
    for(int i=0;i<strlen(two);i++)
    {
        if(islower(two[i]))
        {
            twoLowerLen++;

        }
        
    }

  //  printf("%d and %d",oneLowerLen,twoLowerLen);

    if(oneLowerLen>twoLowerLen)
    {
        printf("'%s' contains %d more lowercase letter(s) than '%s'.",one,(oneLowerLen-twoLowerLen),two);
    }
    if(twoLowerLen>oneLowerLen)
    {
        printf("'%s' contains %d more lowercase letter(s) than '%s'.",two,(twoLowerLen-oneLowerLen),one);
    }
    if(oneLowerLen==twoLowerLen)
    {
        printf("'%s' and '%s' both contain %d lowercase letter(s).",one,two,oneLowerLen);
    }

    return 0;
}