#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *infile = fopen("input.txt","r");
    int count;
    fscanf(infile, "%d",&count);
    int sum = 0;
    for(int i=0;i<count;i++){
        int temp;
        fscanf(infile, "%d",&temp);
        sum += temp;
    }
    fclose(infile);
    printf("%d",sum);
    return 0;
}