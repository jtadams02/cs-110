#include <stdio.h>
#include <stdlib.h>
int main(int argc,char** argv)
{
    int arr[5];
    int arr_2d[5][5];

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            arr_2d[i][j] = (i+1) * (j+1);
        }
    }
     for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",(arr_2d[i][j]));
        }
        printf("\n");
    }


}

