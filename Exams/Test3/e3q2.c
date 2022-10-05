#include <stdio.h>                                                                  
#include <stdlib.h>                                                                 

int verify(int argc, char **argv);
int* buildArray(int size, int start, int inc);

int main (int argc, char **argv) {
    if (!verify(argc, argv)) {
        printf("Invalid arguments\n");
        return 1;
    }
    int *a = buildArray(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
    for (int i = 0; i < atoi(argv[1]); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;                                                                     
}

/*
----------------------------------------------------------------------------
                DO NOT MODIFY ANYTHING ABOVE THIS LINE
*/

/*
Return 1 if valid, 0 if invalid
- 4 arguments
- size > 0
- start > 0
- inc <= start
*/
// ./a.out size start inc
int verify(int argc, char **argv) {
    if(argc==4)
    {
        int size = atoi(argv[1]);
        int start = atoi(argv[2]);
        int inc = atoi(argv[3]);
        if(size>0&&start>0&&inc<=start)
        {
            return 1;
        } else{
            return 0;
        }
        
    } else {
        return 0;
    }

}

// malloc with `size`
// from `start`, fill the array with increments of `inc`
int *buildArray(int size, int start, int inc) {
    int *arr = malloc(size*sizeof(int));
    int i=0;
    while(i<size)
    {
        arr[i] = start;
        start+=inc;
        i++;
    }

    //free(arr);
    return arr;
}
