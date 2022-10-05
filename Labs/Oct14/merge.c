#include <stdio.h>
#include <math.h>

int main(int argc, char** argv){
    FILE* one = NULL;
    FILE* two = NULL;
    int num1;
    int num2;
    int temp;
    one = fopen(argv[1],"r");
    two = fopen(argv[2],"r");
    fscanf(one,"%d",&num1);
    fscanf(two,"%d",&num2);
    if(one==NULL){
        printf("Cannot open file '%s'",argv[1]);
        return 1;
    }
    if(two==NULL){
        printf("Cannot open file '%s'",argv[2]);
        return 1;
    }
    while((!feof(one))&&(!feof(two)))
    {
        if(num1<num2)
        {
            printf("%d ",num1);
            fscanf(one,"%d",&num1);
            continue;
        } else if(num1>num2)
        {   
            printf("%d ",num2);
            fscanf(two,"%d",&num2);
            continue;
        } else if(num1==num2){
            printf("%d ",num1);
            fscanf(one,"%d",&num1);
            fscanf(two,"%d",&num2);
        }

    }
    while(!feof(one)){
        printf("%d ",num1);
        fscanf(one,"%d",&num1);
    }
    while(!feof(two))
    {
        printf("%d ",num2);
        fscanf(two,"%d",&num2);
    }
    fclose(one);
    fclose(two);
    return 0;
}