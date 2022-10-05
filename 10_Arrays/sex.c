#include <stdio.h>


int main(){

    int my_array[69420];
    for(int i=0;i<(sizeof(my_array)/sizeof(int));i++)
    {
        my_array[i] = i;

    }
    for(int i=0;i<(sizeof(my_array)/sizeof(int));i++)
    {
        printf("%d ",my_array[i]);

    }





























































return 0;
}