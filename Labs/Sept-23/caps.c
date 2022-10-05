#include <string.h>
#include <stdio.h>
#include <ctype.h>
int main(void){
    printf("Enter how many words:\n");
    int numWords = 0;
    scanf("%d",&numWords);

    printf("Enter %d words:\n",numWords);
    char bigWord[100];
    char inputWord[50];
    for(int i=0;i<numWords;i++){
        scanf("%s",inputWord);
        if(strlen(inputWord)>3){
            for(int j=0;j<strlen(inputWord);j++)
            {   
                char compare = inputWord[j];
                if(isupper(compare)>0){
                    strncat(bigWord,&compare,1);
                }
            }
        }
    }
    printf("The result is '%s'\n",bigWord);


}