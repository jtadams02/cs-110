#include <stdlib.h>
#include <stdio.h>

int* save_to_array(char* filename, int* size);
void printArray(int arr[], int size);




int main(int argc,char** argv){
    if(argc != 3) return 1;
    int size;
    int* arr = save_to_array(argv[1],&size);
    printArray(arr,size);
    free(arr);

    return 0;
}



int* save_to_array(char* filename, int* size){
    FILE* fp = fopen(filename, "r");
    int count;
    fscanf(fp,"%d",count);
    (*size) = count;

   int* arr = (int*) malloc(sizeof(int)*count);
   for(int i=0;i<count;i++){
       fscanf(fp,"%d",&arr[i]);
   }
    return arr;
} 

void printArray(int arr[], int size){


    printf("[");
    for(int i=0;i<size-1;i++){

        printf("%d,",arr[i]);
    }
    printf("%d]",arr[size-1]);
}