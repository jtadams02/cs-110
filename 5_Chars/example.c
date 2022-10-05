#include <stdio.h>

int main(void) {

  /*  char a = 'A',b = 'B',c = 'M';

    printf("%c %c %c", a,b,c);

    printf("\n%c %c %c",a+1,b+1,c+1);

    printf("\n%c: %d @%p",a+1,a+1,a+1);
    */
   /*
   char swag, two,three;

   printf("Enter a character: ");
   scanf(" %c",&swag);

   printf("Enter a character: ");
   scanf(" %c",&two);

   printf("Enter a character: ");
   scanf(" %c",&three);

    printf("You've entered: %c, %c, and %c.",swag,two,three);

    if(islower(swag))
    {
        printf("\n%c -> %c",swag,toupper(swag));
    } else {
        printf("\n%c is already uppercase!",swag);
    }
    */

    char myString[50];

    scanf("%s",myString);
    printf("You entered the string: %s\n",myString);
    printf("The string is %p\n",myString);
    
    return 0;
}