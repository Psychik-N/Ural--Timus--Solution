#include <stdio.h>
int f[10000010];
int main(){
int k,p,i;
scanf("%d%d",&k,&p);
f[1]=0;
f[2]=1%p;
for(i=3;i<10000010;i++){
if(i%2==0)f[i]=(f[i-1]+f[i/2])%p;
else f[i]=f[i-1];
}
printf("%d",f[k]);
}
