#include <stdio.h>
#include <math.h>
int main(){
double a,b;
scanf("%lf%lf",&a,&b);
printf("%.8lf\n",(a*a+b*b)/4+a*b/sqrt(2));
return 0;
}
