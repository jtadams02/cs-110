/*
*   JT Adams
*   9/10/2021
*   ---------
*   Program that asks the user where to choose one option of where to go, and then takes them on a trip depending on which location they choose
*/




#include <stdio.h>
#include <string.h>


int main(void){
    char * c1C1 = "new-orleans";
    char * c1C2 = "lafayette";
    char * c1C3 = "lake-charles";
    char * c1C4 = "shreveport";
    char * c1C5 = "alexandria";

    char * c2C1 = "nashville";
    char * c2C2 = "memphis";
    char * c2C3 = "murfreesboro";
    char * c2C4 = "chattanooga";
    char * c2C5 = "knoxville";
    char * c2C6 = "gatlinburg";
    char * c2C7 = "asheville";

    char * c3C1 = "milton";
    char * c3C2 = "pensacola";
    char * c3C3 = "destin";
    char * c3C4 = "panama-city";
    char * c3C5 = "tallahassee";
    char * c3C6 = "st-augustine";
    char * c3C7 = "gainesville";
    char * c3C8 = "ocala";
    char * c3C9 = "daytona";
    char * c3C10 = "kissimmee";
    char * c3C11 = "tampa";
    char * c3C12 = "jacksonville";
    char * c3C13 = "clearwater";
    char * c3C14 = "fort-myers";
    char * c3C15 = "miami";
    char * c3C16 = "orlando";
    char * c3C17 = "west-palm";
    char * c3C18 = "fort-lauderdale";
    char * c3C19 = "st-petersburg";

    char * c4C1 = "atlanta";
    char * c4C2 = "athens";
    char * c4C3 = "columbus";
    char * c4C4 = "augusta";
    char * c4C5 = "macon";
    char * c4C6 = "savannah";
    char * c4C7 = "tybee-island";
    char * c4C8 = "warner-robins";
    char * c4C9 = "albany";
    char * c4C10 = "fernandina"; 
    char * c4C11 = "brunswick";


    char input[50];

    printf("From tuscaloosa: new-orleans, nashville, milton, or atlanta? ");
    
    scanf("%s",input);



 //  printf("%s",input);

  if(strcmp(input,c1C1)== 0)
  {
    printf("From %s: %s or %s? ",c1C1,c1C2,c1C3);
    scanf("%s",input);
    if(strcmp(input,c1C2)==0)
    {
      printf("You ended your trip in %s!",c1C2);
    } else if(strcmp(input,c1C3)==0)
    {
      printf("From %s: %s or %s? ",c1C3,c1C4,c1C5);
      scanf("%s",input);

      if(strcmp(input,c1C4)==0)
      {
        printf("You ended your trip in %s!",c1C4);
      } else if(strcmp(input,c1C5)==0)
      {
        printf("You ended your trip in %s!",c1C5);
      } else {
        printf("You ended your trip in %s!",c1C3);
      }
    } else 
    {
      printf("You ended your trip in %s!",c1C1);
    }







  } else if(strcmp(input,c2C1)==0)
  {
    printf("From %s: %s or %s? ",c2C1,c2C2,c2C3);
    scanf("%s",input);

    if(strcmp(input,c2C2)==0){
      printf("You ended your trip in %s!",c2C2);
    } else if (strcmp(input,c2C3)==0){
      printf("From %s: %s or %s? ",c2C3,c2C4,c2C5);
      scanf("%s",input);

      if(strcmp(input,c2C4)==0){
        printf("From %s: %s or %s? ",c2C4,c2C6,c2C7);
        scanf("%s",input);

        if(strcmp(input,c2C6)==0){
          printf("You ended your trip in %s!",c2C6);
        } else if(strcmp(input,c2C7)==0){
          printf("You ended your trip in %s!",c2C7);
        } else{
          printf("You ended your trip in %s!",c2C4);
        }
      } else if(strcmp(input,c2C5)==0){
        printf("You ended your trip in %s!",c2C5);
      } else {
        printf("You ended your trip in %s",c2C3);
      }
    } else {
      printf("You ended your trip in %s",c2C1);
    }







  } else if(strcmp(input,c3C1)==0)
  {
    printf("From %s: %s or %s or %s? ",c3C1,c3C2,c3C3,c3C4);
    scanf("%s",input);

    if(strcmp(input,c3C2)==0)
    {
      printf("From %s: %s or %s? ",c3C2,c3C5,c3C6);
      scanf("%s",input);
      
      if(strcmp(input,c3C5)==0){
        printf("From %s: %s or %s? ",c3C5,c3C7,c3C8);
        scanf("%s",input);

        if(strcmp(input,c3C7)==0)
        {
          printf("You ended your trip in %s!",c3C7);
        } else if(strcmp(input,c3C8)==0)
        {
          printf("You ended your trip in %s!",c3C8);
        } else 
        {
          printf("You ended your trip in %s!",c3C5);
        }
      } else if(strcmp(input,c3C6)==0)
      {
        printf("You ended your trip in %s!",c3C6);
      } else {
        printf("You ended your trip in %s!",c3C2);
      }


    } else if(strcmp(input,c3C3)==0)
    {
      printf("From %s: %s or %s? ",c3C3,c3C9,c3C10);
      scanf("%s",input);

      if(strcmp(input,c3C9)==0)
      {
        printf("You ended your trip in %s!",c3C9);
      } else if(strcmp(input,c3C10)==0)
      { 
        printf("You ended your trip in %s!",c3C10);
      } else 
      {
        printf("You ended your trip in %s!",c3C3);
      }



    }else if(strcmp(input,c3C4)==0)
    {
      printf("From %s: %s or %s? ",c3C4,c3C11,c3C12);
      scanf("%s",input);

      if(strcmp(input,c3C11)==0)
      {
        printf("You ended your trip in %s!",c3C11);
      } else if(strcmp(input,c3C12)==0)
      {
        printf("From %s: %s or %s or %s? ",c3C12,c3C13,c3C16,c3C19);
        scanf("%s",input);

        if(strcmp(input,c3C13)==0)
        {
          printf("From %s: %s or %s? ",c3C13,c3C14,c3C15);
          scanf("%s",input);

          if(strcmp(input,c3C14)==0)
          {
            printf("You ended your trip in %s!",c3C14);
          } else if(strcmp(input,c3C15)==0)
          {
            printf("You ended your trip in %s!",c3C15);  
          } else {
            printf("You ended your trip in %s!", c3C13);
          }
        } else if(strcmp(input,c3C16)==0)
        {
          printf("From %s: %s or %s? ",c3C16,c3C17,c3C18);
          scanf("%s",input);

          if(strcmp(input,c3C17)==0)
          {
            printf("You ended your trip in %s!",c3C17);
          } else if(strcmp(input,c3C18)==0)
          {
            printf("You ended your trip in %s!",c3C18);
          } else {
            printf("You ended your trip in %s!",c3C16);
          }
        } else {
          printf("You ended your trip in %s!",c3C19);
        }
      } else {
        printf("You ended your trip in %s!",c3C19);
      }

    }   







  } else if(strcmp(input,c4C1)==0)
  {
    printf("From %s: %s or %s ",c4C1,c4C2,c4C3);
    scanf("%s",input);

    if(strcmp(input,c4C2)==0)
    {
      printf("From %s: %s or %s? ",c4C2,c4C4,c4C5);
      scanf("%s",input);

      if(strcmp(input,c4C4)==0)
      {
        printf("From %s: %s or %s? ",c4C4,c4C6,c4C7);
        scanf("%s",input);

        if(strcmp(input,c4C6)==0){
          printf("You ended your trip in %s!",c4C6);
        } else {
          printf("You ended your trip in %s!",c4C7);
        }
      } else {
        printf("You ended your trip in %s!",c4C5);
      }


    } else if(strcmp(input,c4C3)==0)
    {
      printf("From %s: %s or %s? ",c4C3,c4C8,c4C9);
      scanf("%s",input);

      if(strcmp(input,c4C8)==0)
      {
        printf("You ended your trip in %s!",c4C8);

      } else {
        printf("From %s: %s or %s? ",c4C9,c4C10,c4C11);
        scanf("%s",input);

        if(strcmp(input,c4C10)==0){
          printf("You ended your trip in %s!",c4C10);

        }else{
          printf("You ended your trip in %s!", c4C11);
        }
      }


    }  else {
      printf("You ended your trip in %s!",c4C1);
    }













  } else {
    printf("No plan is the best plan");
  }

    return 0;
}