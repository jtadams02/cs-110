#include <stdio.h>
#include <string.h>
int main(){

    int nums;
    int num[26] ={0};
    int c = 0;

    char word[50];

    printf("Enter your input:\n");

    while(scanf("%s",word)!= EOF){

        scanf("%s", word);

        nums = 0;

        for(int i=0;i<strlen(word);i++)
        {
           int number = ((int)word[i])-97;
            nums[number]++;
        }

    }

    for(int i=0; i<26; i++){

        if(num[i]==0){

            if(c==0)

                printf("Missing letters:");

            printf(" %c", i+'a');

            c++;

        }

    }

    if(c==0)

        printf("Your input contains all the letters");

    printf("\n");

    return 0;

}