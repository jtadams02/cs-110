#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {

   /* Type your code here. */
    int password = 0;
    char word[50];
    printf("Password: ");
    scanf("%d",&password);
    printf("\n");

    printf("Message: ");
    scanf("%s",word);
    printf("\n");

    for(int i=0;i<strlen(word);i++)
    {
        if(islower(word[i])!=0)
        {
            printf("%d ",(word[i]+password));}
    }   
    

   return 0;
}
