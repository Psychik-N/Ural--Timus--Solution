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
a[n+2]=d;
for(i=1;i<=n;i++){
scanf("%lf",&d);
c[i]=d;
}
while(v1-v2>0.00001){
a[1]=(v1+v2)/2;
for(i=2;i<=n+1;i++)
a[i]=2*(a[i-1]+c[i-1])-a[i-2];
if(abs(a[n+1]-a[n+2])<0.00001){
printf("%.2lf",a[1]);
return 0;
}
else if(a[n+1]>a[n+2])v2=a[1];
else v1=a[1];
}
}
