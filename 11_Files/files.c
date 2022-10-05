#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("foobar2.jpg","w");
    fprintf(fp, "Roll Tide\n");
    fclose(fp);


    return 0;
}