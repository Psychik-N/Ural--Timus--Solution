#include <stdio.h>
#include <math.h>
#define pi 3.1415926535
int main(){
    double v,a,m;
    scanf("%lf%lf%lf",&v,&a,&m);
    printf("%.2lf",2*sin(a*pi/180)*cos(a*pi/180)*v*v/10.0/(1-1/m));
}
