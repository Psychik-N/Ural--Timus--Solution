#include <stdio.h>
#include <math.h>
int main(){
    double a,b,c;
    int d=0;
    scanf("%lf%lf%lf",&a,&b,&c);
    c=1-c/100;
    printf("%d\n",(int)(log(b/a)/log(c)+0.9999999));
}

