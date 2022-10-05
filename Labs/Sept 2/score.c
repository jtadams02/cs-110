#include <stdio.h> 

int main(void) {
    int one,two,three,four;
    double avg;
    int arr[4];
    
    for(int i=0;i<4;i++)
    {
        scanf("%d",&arr[i]);
    }

    

    for(int i=0;i<4;i++)
    {
        int min = arr[i];
        for(int j=i+1;j<4;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

    }

  /*  for(int i=0;i<4;i++)
    {
        printf("%d ",arr[i]);
    }
*/

    avg = ((double)(arr[1]+arr[2]+arr[3])/3);

    printf("%lf",avg);

    //printf("%d %d %d %d",one,two,three,four);



    /*if((one<two&&one<three&&one<four))
    {   
        if(one!=two&&one!=three&&one!=four)
        {
            avg = ((double)(two+three+four)/3);
        }
        
    } else if(two<one&&two<three&&two<four){
        avg = ((double)(one+three+four)/3);
    } else if(three<one&&three<two&&three<four){
        avg = ((double)(one+two+four)/3);
    } else {
        avg = ((double)(one+two+three)/3);
    }

    printf("%lf",avg);*/
    









    return 0;
}