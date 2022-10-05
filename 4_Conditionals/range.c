#include <stdio.h>

int main() {
    int one,two,three;
    int high,low;

    printf("Enter 3 integers: ");   
    scanf("%d %d %d", &one,&two,&three);

     if(one<two && one<three){
        low = one;
    } else if(two<one && two<three)
    {
        low = two;
    } else{
        low = three;
    }

    if(one>two&&one>three){
        high = one;
    } else if(two>one&&two>three){
        high = two;
    } else {
        high = three;
    }

    printf("\nThe range is %d",(high-low));
    return 0;
}