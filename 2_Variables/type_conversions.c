#include <stdio.h>

int main() {
    int a=2, b=3, c=6;
    double z1=(a+b+c);
    double z2=(a+b+c)/3.0;
    double z3=((double)a+b+c)/3;
    double y=0.2*c+1/5*c+c/5+c/5.0+(double)c/5;
    double x = 3.6;
    int i1=x;
    int i2=floor(x);
    int i3=ceil(x);
    int i4=round(x);
    double y2 = (int)x;
    return 0;
}