#include <stdio.h>
int main(){
int f[60]={0,1,1,2},i,n;
for(i=4;i<60;i++)
f[i]=f[i-1]+f[i-3]+1;
scanf("%d",&n);
printf("%d",f[n]);
}
