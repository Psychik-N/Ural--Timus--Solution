#include <stdio.h>
int main(){
int i,m[7];
for(i=0;i<7;i++)scanf("%d",&m[i]);
for(i=0;i<8;i++)
if(((m[1]+m[2]+m[3])%2==m[4])&&((m[0]+m[2]+m[3])%2==m[5])&&((m[0]+m[1]+m[3])%2==m[6]))break;
else{
m[i]=!m[i];
m[i-1]=!m[i-1];
}
for(i=0;i<7;i++) printf("%d ",m[i]);
}