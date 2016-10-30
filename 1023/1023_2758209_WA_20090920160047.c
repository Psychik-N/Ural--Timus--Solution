#include <stdio.h>
#include <math.h>
int main(){
int n,k,l,m;
scanf("%d",&n);
m=(int)(sqrt((double)n)+0.0001);
for(l=3;l<=m;l++)if(n%l==0){printf("%d",l-1);}
if(n%2==0)printf("%d",n/2);
else printf("%d",n-1);
}