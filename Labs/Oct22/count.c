#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv){
    int upper = 0;
    int lower = 0;
    int digit = 0;
    char* stringy= argv[1];
    for(int i=0;i<strlen(stringy);i++)
    {
        if(isupper(stringy[i])!=0)
        {
            upper++;
        }
        if(islower(stringy[i])!=0)
        {
            lower++;
        }
        if(isdigit(stringy[i])!=0)
        {
            digit++;
        }
    }

    printf("Uppers = %d\n",upper);
    printf("Lowers = %d\n",lower);
    printf("Digits = %d\n",digit);

    return 0;
}