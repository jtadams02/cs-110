#include <stdio.h>
#include <string.h>
#include <ctype.h>

void left(char word[]);
void right(char word[]);
void inc(char word[]);
void dec(char word[]);

int main(int argc, char** argv) {
   //ERRORS
   if(argc!=3)
   {
      printf("Invalid number of arguments\n");
      return -1;
   }
   FILE *inFile = NULL;
   inFile = fopen(argv[1],"r");
   if(inFile == NULL)
   {
      printf("Could not open file '%s'",argv[1]);
      return -1;
   }
   char argument[100];
   strcpy(argument,argv[2]);
   int aLen = strlen(argument);
   for(int i=0;i<aLen;i++)
   {
      if((argument[i]!='R')&&(argument[i]!='L')&&(argument[i]!='I')&&(argument[i]!='D'))
      {
         printf("You threw off my schwiftiness with schwifty '%c'!",argument[i]);
         return -1;
      }
   }

   

   
   // EVERYTHING ELSE
   while(1)
   {
      char word[100];
      fscanf(inFile,"%s",word);
      if(feof(inFile))
      {
         break;
      } else {
      for(int i=0;i<aLen;i++)
      {
         if(argument[i]=='R')
         {
            right(word);
         }
         if(argument[i]=='L')
         {
            left(word);
         }
         if(argument[i]=='I')
         {
            inc(word);
         }
         if(argument[i]=='D')
         {
            dec(word);
         }
      }
      printf("%s\n",word);
      }
   }
   




   return 0;
}

void left(char word[]) 
{
   int len = strlen(word);
   char newChar = word[0];
   int t = 0;
  char temp = word[0];
   for(int i=1;i<strlen(word);i++)
   {
        //char newTemp = word[i];
        word[i-1]=word[i];
   }
   word[len-1] = temp;

   
   
}

void right(char word[]) 
{
   int len = strlen(word);
   char newChar[100];
   int t = 0;
   char temp = word[strlen(word)-1];
   for(int i=strlen(word)-1;i>0;i--)
   {
      word[i] = word[i-1];
   }
   word[0] = temp;
}

void inc(char word[]) 
{
   for(int i=0;i<strlen(word);i++)
    {
        if(isdigit(word[i]))
        {
            if(word[i]=='9')
            {
                word[i]='0';
            } else {
            word[i] = word[i]+1;
            }
        }else if(isalpha(word[i]))
        {
            if(word[i]=='z')
            {
                word[i] = 'a';
            } else if(word[i]=='Z')
            {
                word[i] = 'a';
            } else {
            word[i] = word[i]+1;
            }
        }
    }
}

void dec(char word[]) 
{
   for(int i=0;i<strlen(word);i++)
    {
        if(isdigit(word[i]))
        {
            if(word[i]=='0'){
                word[i]='9';
            } else {
                word[i] = word[i]-1;
            }
        } else if(isalpha(word[i]))
        {
            if(word[i]=='a'){
                word[i]='z';
            }else if(word[i]=='A'){
                word[i]='Z';
            } else {
                word[i]=word[i]-1;
            }
        }
    }
}
