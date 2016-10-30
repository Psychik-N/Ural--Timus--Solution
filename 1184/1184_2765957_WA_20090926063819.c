#include <stdio.h>
int main(){
int n,k,i,l[10010],p1=0,p2=100000,mid,tt;
double in;
scanf("%d%d",&n,&k);
for(i=0;i<n;i++){
scanf("%lf",&in);
l[i]=(int)(in*100+(1e-9));
}
while(p1!=p2){
mid=(p1+p2)/2+1;
tt=0;
for(i=0;i<n;i++)tt+=l[i]/mid;
if(tt<k)p2=mid-1;
else p1=mid;
}
printf("%.2lf",(double)p1/100.0+(1e-9));
}
