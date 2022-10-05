#include <stdio.h>

int main(){
   // setbuf(stdout, NULL); 
    int max=0;
    int min=0;
    int num = 0;
    scanf("%d",&num);
    max = num;
    min = num;
    while(scanf("%d",&num)!=EOF)
    {
        if(num>max)
        {
            max = num;
        }
        if(num<min){
            min = num;
        }
        
    }

    int range = max -min;
    printf("Range of input = %d",range);
    
    return 0;
}