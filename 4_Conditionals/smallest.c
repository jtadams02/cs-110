#include <stdio.h>

int main()
{
    int one, two, three;

    printf("Enter 3 integers: ");   
    scanf("%d %d %d", &one,&two,&three);

    if(one<two && one<three){
        printf("%d is the smallest",one);
    } else if(two<one && two<three)
    {
        printf("%d is the smallest",two);
    } else{
        printf("%d is the smallest",three);
    }
}