#include <stdio.h>
int main(){
int i,n,a[5000],c[5000],v1=-200000,v2=200000;
double d;
scanf("%d",&n);
scanf("%lf",&d);
a[0]=(int)(d*100);
scanf("%lf",&d);
a[n+2]=(int)(d*100);
for(i=1;i<=n;i++){
scanf("%lf",&d);
c[i]=(int)(d*100);
}
while(1){
a[1]=(v1+v2)/2;
for(i=2;i<=n+1;i++)
a[i]=2*a[i-1]-a[i-2]+2*c[i-1];
if(a[n+1]<a[n+2])v1=a[1]+1;
else if(a[n+1]>a[n+2])v2=a[1]-1;
else{
printf("%d.%d",a[1]/100,a[1]%100);
return 0;
}
}
}
