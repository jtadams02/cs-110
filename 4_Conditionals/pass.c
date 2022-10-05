#include <stdio.h>

int main() {
    double score;
    printf("Enter a score: ");

    scanf("%lf",&score);
    char grade;

    if(score >= 90)
    {
        printf("\nPassed with a grade of A");
    } else if(score>=80 && score <90)
    {
        printf("\nPassed with a grade of B");
    }else if(score>=70&&score<80){
        printf("\nPassed with a grade of C");
    } else if(score >=60&&score<70){
        printf("\nPassed with a grade of D");
    } else {
        printf("\nFailed, you got a F");
    }

    /*
    if(score >= 60){
        printf("\nPassed with a grade of %s", grade);
    } else {
        printf("\nFailed, you got a %s",grade);
    }
    */

   
    return 0;
}