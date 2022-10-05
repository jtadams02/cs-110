/*
* Expression Tester
* Noah Gershmel
* 8/27/2021
* ----------------
* Use this file to test the truth value of expressions
* Usage:
*   Change the value of the expression defined as `EXPRESSION` on line 13
*/

#include <stdio.h>      //Contains printf()

#define EXPRESSION 5 == 4 || 3 > 2

/* Runs the expression tester */
int main () {
    /* A simple if/else to display the results of the expression */
    if (EXPRESSION) {
        printf("true (%d)\n", EXPRESSION);
    } else {
        printf("false (%d)\n", EXPRESSION);
    }

    //Return 0 from main
    return 0;
}