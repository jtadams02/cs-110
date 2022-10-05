#include <stdio.h>


void manip(int arr_in[][4], int rows, int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(i==j) arr_in[i][j] =0;
        }
    }
}

void printArray(int arr_in[][4], int rows, int cols)
{
    
    for(int i=0;i<rows;i++)
    {
        printf("{ ");
        for(int j=0;j<cols;j++)
        {
            printf("%d ",arr_in[i][j]);
        }
        printf("}");
        printf("\n");
    }
}

int sum(int **arr, int rows, int cols)
{
    int total = 0;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            total += arr[i][j];
        }
    }

}

int main() {

    int my_array[3][4] = {
        {1,2,3,4},{5,6,7,8},{9,10,11,12}
    };
    manip(my_array,3,4);
    printArray(my_array,3,4);
    return 0;
}

