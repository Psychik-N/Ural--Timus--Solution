#include <stdio.h>
#include <math.h>
int main(){
int i,n;
double a[5000],c[5000],v1=-2000,v2=2000;
char in[20];
scanf("%d",&n);
scanf("%lf %lf",&a[0],&a[n+2]);
for(i=1;i<=n;i++)
scanf("%ld",c[i]);
while(1){
a[1]=(v1+v2)/2;
for(i=2;i<=n+1;i++)
a[i]=2*a[i-1]-a[i-2]+2*c[i-1];
if(abs(a[n+1]-a[n+2])<0.001){
printf("%d.%d",a[1]/100,a[1]%100);
return 0;
}
else if(a[n+1]>a[n+2])v2=a[1]-1;
else v1=a[1]+1;
}
}
