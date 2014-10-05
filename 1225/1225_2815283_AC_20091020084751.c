#include <stdio.h>
int main(){
unsigned int f[50]={0,1};
int i,n,t;
for(i=2;i<50;i++)f[i]=f[i-1]+f[i-2];
scanf("%d",&n);
printf("%u\n",f[n]*2);
}
