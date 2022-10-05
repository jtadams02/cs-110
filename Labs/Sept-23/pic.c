    #include <stdio.h>

    int main() {
        
        int num = 0;
        scanf("%d",&num);

        for(int i=0;i<num;i++){
            if(i==0||i==num-1){
            for(int j=0;j<num;j++){
                printf("X");
            }
            }else{
            printf("X");
            for(int j=num-(num-1);j<num-1;j++)
            {
                printf(" ");
            }
            printf("X");
            }
            printf("\n");
        }




        return 0;
    }