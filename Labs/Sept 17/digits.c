#include <stdio.h>

#include <string.h>

int main(){
    int integer=0;
    int total=0;
    scanf("%d",&integer);

    while(integer>0)
    {
        total += (integer%10);
        integer = (integer/10);
    }

    printf("%d",total);

    return 0;
}