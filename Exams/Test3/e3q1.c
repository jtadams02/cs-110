#include <stdio.h>         
#include <stdlib.h>                                                         

int selectInts(char *input_filename, char *out_filename, int lower, int upper);

int main (int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s <input_file> <output_file> <lower> <upper>\n", argv[0]);
        return 1;
    }
    int count = selectInts(argv[1], argv[2], atoi(argv[3]), atoi(argv[4]));
    printf("%d numbers selected\n", count);

    return 0;                                                                       
}

/*
----------------------------------------------------------------------------
                DO NOT MODIFY ANYTHING ABOVE THIS LINE
*/

// read ints from input_filename until EOF and
// write to output_filename the ints between lower and upper (inclusive)
int selectInts(char *input_filename, char *output_filename, int lower, int upper) {
    // RETURN -1 IF THE FILES CANNOT BE OPENED
    FILE *inFile = NULL;
    FILE *outFile = NULL;
    int count = 0;
    inFile=fopen(input_filename,"r");
    outFile=fopen(output_filename,"w");
    if(inFile==NULL)
    {
       // printf("Input file not found");
        return -1;
    }
    if(outFile==NULL)
    {
       // printf("Output file not found");
        return -1;
    }
    while(!feof(inFile))
    {
        int num;
        fscanf(inFile,"%d",&num);
        if(num>=lower&&num<=upper)
        {
            fprintf(outFile,"%d ",num);
            count++;
        }
        
    }

    // CLOSE YOUR FILES
    fclose(inFile);
    fclose(outFile);
    // RETURN HOW MANY INTS WERE WRITTEN TO THE OUTPUT
    return count;
}
