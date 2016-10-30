#include <stdio.h>
#include <math.h>
int main(){
int i,n;
double a[5000],c[5000],v1=-2000.00,v2=2000.00;
double d;
scanf("%d",&n);
scanf("%lf",&d);
a[0]=d;
scanf("%lf",&d);
a[n+1]=d;
for(i=1;i<=n;i++){
scanf("%lf",&d);
c[i]=d;
}
while(v1-v2>0.00001){
a[1]=(v1+v2)/2.0;
for(i=2;i<=n;i++)
a[i]=2*(a[i-1]+c[i-1])-a[i-2];
d=2*(a[n]+c[n])-a[n-1];
if(fabs(a[n+1]-d)<0.00001){
printf("%.2lf",a[1]);
return 0;
}
else if(d>a[n+1])v2=a[1];
else v1=a[1];
}
printf("%.2lf",v1);
}
