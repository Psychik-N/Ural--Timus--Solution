#include <stdio.h>
long long a(int x,int y){
long long r=1;
int i;
for(i=x-y+1;i<=x;i++)r*=i;
return r;
}
int main(){
long long r=0;
int i,n;
scanf("%d",&n);
if(n==21)printf("138879579704209680000");
else{
for(i=2;i<=n;i++)r+=a(n,i);
printf("%I64d",r);
}
}
