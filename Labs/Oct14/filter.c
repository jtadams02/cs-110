#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  

int main(int argc, char** argv){
    FILE* inputFile = NULL;
    FILE* outputFile = NULL;
    char name[100];
    char outname[100];
    strcpy(outname,argv[2]);
    strcpy(name,argv[1]);
    inputFile = fopen(("%s",name),"r");
    outputFile = fopen(("%s",outname),"w");
    if(inputFile == NULL){
        printf("Cannot open file '%s'",argv[1]);
        return 1;
    }
    if(outputFile==NULL)
    {
        printf("cannot open file '%s'",argv[2]);
        return 1;
    }
    char word[50];
    while(fscanf(inputFile,"%s",word)!=EOF)
    {
        int counter = 0;
        for(int i=0;i<strlen(word);i++)
        {
            char ch = word[i];
            if(isalpha(ch)!=0)
            {
                counter++;
            }
        }
        if(counter==strlen(word))
        {
            fprintf(outputFile,"%s ",word);
        }
         
       //printf("%s ",word);
    }
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}