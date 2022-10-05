#include <stdio.h>

int main(void) {

    int num;
    printf("Enter a number: ");
    scanf("%d",&num);

    int count = 0;
    int c = num;
    int cc = num;
    while(c>0)
    {
        count++;
        
        c = c/10;

    }
    int arr[count];
    int duplicates = 0;
    for(int i=0;i<count;i++)
    {
        arr[i] = cc%10;
        cc = cc/10;
    }
    for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++){
            if(arr[i]==arr[j]){

                duplicates++;
            }

        }

    }

    if(duplicates>0){
        printf("Duplicate digits found");
    } else {
        printf("No duplicate digits found");
    }
    
    //printf("%d",count);
    




    return 0;
}