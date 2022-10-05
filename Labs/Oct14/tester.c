#include <stdio.h>
#include <string.h>

int main()
{
    char word[] = "Word";
    printf("Length: %d",strlen(word));
    int counter =0;
    for(int i=0;i<strlen(word);i++)
    {
        counter++;
    }
    printf("Counter Len: %d",counter);
    
    return 0;
}