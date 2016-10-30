#include <stdio.h>
#include <math.h>
int main(){
double l,h,w,t,r;
scanf("%lf%lf%lf",&l,&h,&w);
if(h<l/2){puts("butter");return 0;}
t=sqrt((2*h-l)/9.81);
r=w*t/60.0;
r-=floor(r);
if(r>0.25&&r<0.75)puts("bread");
else puts("butter");
return 0;
}
