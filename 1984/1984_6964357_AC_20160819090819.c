#include <stdio.h>
#include <math.h>
int main(){
double n;
scanf("%lf",&n);
printf("%.8lf\n",n==1?1.0:1.0/cos(M_PI*(n-2)/(2*n))+1.0);
return 0;
}
