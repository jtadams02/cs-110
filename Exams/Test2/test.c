#include <stdio.h>
#include <string.h> 
#include <ctype.h>
int main() {
    char word[50];
    int counter = 0;
    scanf("%s",word);
    printf("Length: %d\n",strlen(word));
    for(int i=0;i<strlen(word);i++)
    {
        counter++;
    }
    printf("Counter: %d",counter);
   return 0;
}
