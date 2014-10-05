#include <stdio.h>
int main(){
int n,k,i,t,l1=0,l2=1;
scanf("%d %d",&n,&k);
for(i=1;i<=n;i++){
t=(l1+l2)*(k-1);
l1=l2;
l2=t;
}
printf("%d",l2);
}
