#include<stdio.h>
#include<stdlib.h>

int threes(int val);

int main(int argc, char *argv[]) {
    int val = atoi(argv[1]);
    printf("%d contains %d threes.\n", val, threes(val));
    return 0;
}



int threes(int val){
    int counter = 0;
    while (val > 0) {
        if ((val % 10) == 3) {
            ++counter;
        }
        val /= 10;
    }
    return counter;
}