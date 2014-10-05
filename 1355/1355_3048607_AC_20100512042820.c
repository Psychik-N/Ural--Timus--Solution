#include <stdio.h>
#include <math.h>
int main(){
int i,j,n,k,t,l,c;
scanf("%d",&n);
for(i=0;i<n;i++){
c=0;
scanf("%d%d",&t,&k);
if(k%t!=0)goto nxt;
k/=t;
start:
c++;
if(k==1)goto nxt;
l=(int)sqrt(k);
for(j=2;j<=l;j++)if(k%j==0){
k/=j;
goto start;
}
c++;
nxt:
printf("%d\n",c);
}
}
