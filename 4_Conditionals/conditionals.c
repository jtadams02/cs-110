/*
* Conditionals Examples
* Noah Gershmel
* 8/27/2021
* ---------------------
* Examples of different if statement formats
* This list is non-exhaustive
*/

#include <stdio.h>      //Contains printf()

/* All examples contained sequentially within main */
int main() {
    // <1> If statement with only a single statement
    if (5 != 4) printf("1-True\n");

    // <2> If statement with an else branch, each with only a single statement
    if (8 % 3 == 0) printf("2-True\n");
    else printf("2-False\n");

    // <3> If statement with a statement list
    if (6 * 6 > 32) {
        printf("3-True\n\t(stmt 1)\n");
        printf("\t(stmt 2)\n");
        printf("\t(stmt 3)\n");
    } 

    // <4> Cascading If Else
    if (0 > 2) {
        printf("4-True (if) \n");
    } else if (1 > 2) {
        printf("4-True (else if 1)\n");
    } else if (2 > 2) {
        printf("4-True (else if 2)\n");
    } else if (3 > 2) {
        printf("4-True (else if 3)\n");
    } else {
        printf("4-All False\n");
    }

    //Return from main with no errors
    return 0;
}