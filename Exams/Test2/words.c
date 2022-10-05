#include <stdio.h>
#include <string.h> 
#include <ctype.h>
int main() {
    char word[50];
    printf("Enter words: \n");
    scanf("%s",word);
    int len=0;
    while(strcmp(word,"end")!=0)
    {
        //int stringLen = strlen(word);
        
        int counter = 0;
        for(int i=0;i<strlen(word);i++)
        {
            if(islower(word[i])>0)
            {
                counter++;
            }
        }
        if(counter == strlen(word))
        {
            if(len<counter)
            {
                len = counter;
            }
        }
        scanf("%s",word);
    }
    printf("Longest all lowercase word length: %d",len);
   return 0;
}
