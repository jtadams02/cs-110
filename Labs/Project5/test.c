#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

int main() {

    char word[100];
    printf("Enter Word:\n");
    scanf("%s",word);

    printf("%s\n\n",word);
    char revWord[100];
    int t = 0;
    char temp = word[strlen(word)-1];
    for(int i=0;i<strlen(word);i++)
    {
        if(isdigit(word[i]))
        {
            if(word[i]=='0'){
                word[i]='9';
            } else {
                word[i] = word[i]-1;
            }
        } else if(isalpha(word[i]))
        {
            if(word[i]=='z'){
                word[i]='a';
            }else if(word[i]=='Z'){
                word[i]='A';
            } else {
                word[i]=word[i]-1;
            }
        }
    }
    printf("%s",word);
}   