#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char word[100];
    printf("Enter a token to identify, EOF to stop:\n");
   // char a[50] = ("The token is a ");
    while(scanf("%s",word)!=EOF)
    {
        int intCount = 0;
        int charCount = 0;
        int periodCount = 0;
        int dashCount = 0;
        int len = strlen(word);
        for(int i=0;i<strlen(word);i++)
        {
            if(isdigit((int)word[i]))
            {
                intCount++;
            }

            if(isalpha((int)word[i]))
            {
                charCount++;
            }
            if(word[i]=='.')
            {
                periodCount++;
            }
            if(word[i]=='-')
            {
                dashCount++;
            }
        }
    if(len==36&&dashCount==4)
        //      GUID
        {
            printf("The token is a guid\n");
            printf("Enter a token to identify, EOF to stop:\n");
            continue;
        }

    else if (word[0]=='0'&&word[1]=='b'&&len>2&&dashCount==0)
    // BINARY
        {
            printf("The token is a binary number\n");
            printf("Enter a token to identify, EOF to stop:\n");
            continue;
        }

//      FLOATS
        else if(periodCount==1&&dashCount==0&&charCount==0)
        {
            printf("The token is a positive floating-point number\n");
            printf("Enter a token to identify, EOF to stop:\n");
            continue;

        } else if(periodCount==1&&word[0]=='-'&&charCount==0&&dashCount==1)
        {
            printf("The token is a negative floating-point number\n");
            printf("Enter a token to identify, EOF to stop:\n");
            continue;
        }

//      INTS
        else if(intCount==len&&charCount==0&&dashCount==0&&periodCount==0)
        {
            printf("The token is a positive integer\n");
            printf("Enter a token to identify, EOF to stop:\n");
            continue;
        }
        else if(periodCount==0&&word[0]=='-'&&charCount==0&&dashCount==1)
        {
            printf("The token is a negative integer\n");
            printf("Enter a token to identify, EOF to stop:\n");
            continue;
        }
        else {

//      OTHER
        printf("The token cannot be identified\n");
        printf("Enter a token to identify, EOF to stop:\n");
        }
    }


    return 0;
}