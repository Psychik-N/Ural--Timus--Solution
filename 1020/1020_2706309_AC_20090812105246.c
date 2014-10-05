#include <stdio.h>
#include <math.h>
int main(){
    double l=0,x[1000],y[1000],r;
    int n,i;
    scanf("%d %lf",&n,&r);
    for(i=0;i<n;i++)
      scanf("%lf %lf",&x[i],&y[i]);
    x[n]=x[0];
    y[n]=y[0];
    for(i=0;i<n;i++)
      l+=sqrt((x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]));
    printf("%.2lf",l+2*3.14159265359*r);
}
