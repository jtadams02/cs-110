#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    if(argc<2){
        printf("This program requires at least one argument");
        return 1;
    }

    int counter = argc;
    double max=-9999.0; 
    double min=9999.0;
    for(int i=1;i<argc;i++)
    {
        char arg[100];
        strcpy(arg,argv[i]);
        double num = atof(arg);
        if(num>max)
        {
            max=num;
        }
        if(num<min)
        {
            min=num;
        }
    }
    double diff = (max-min);
    printf("The range of these %d values is %lf",argc-1,diff);

    return 0;
}