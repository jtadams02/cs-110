#include <stdio.h>
#include <string.h>
int main(void){

    char *words;
    char input[50];
    int aCount = 0;
    int eCount = 0;
    int iCount = 0;
    int oCount = 0;
    int uCount = 0;

    while(scanf("%s",input)!=EOF)
    {
        //char word[50] = input;
        
        for(int i=0;i<strlen(input);i++){
            char compare = input[i];
            if(compare == 'a'){
                aCount++;
            }
            if(compare == 'e'){
                eCount++;
            }
            if(compare == 'i'){
                iCount++;
            }
            if(compare == 'o'){
                oCount++;
            }
            if(compare == 'u'){
                uCount++;
            }
        }
    }
    printf("The vowel a occurred %d times\n",aCount);
    printf("The vowel e occurred %d times\n",eCount);
    printf("The vowel i occurred %d times\n",iCount);
    printf("The vowel o occurred %d times\n",oCount);
    printf("The vowel u occurred %d times\n",uCount);








}