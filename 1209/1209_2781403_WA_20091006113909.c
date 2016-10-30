#include <stdio.h>
#include <math.h>
int main(){
int n,k,i,t;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&k);
t=(int)sqrt((k-1)*2);
if(t*(t+1)/2+1==k)printf("1 ");
else printf("0 ");
}
}
