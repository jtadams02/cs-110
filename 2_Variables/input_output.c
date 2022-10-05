#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a); //%d-ints %c-chars %lf-longfloats %s-shorts %p- %f-floats?

    double b;
    scanf("%lf", &b);

    int x=3;
    double y=4.5;
    printf("a is %d, \tb is %.2lf\n", x/2, 3*y);
}