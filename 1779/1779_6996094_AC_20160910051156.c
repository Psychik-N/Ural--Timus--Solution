#include <stdio.h>
int main(){
int n,i,j;
scanf("%d",&n);
printf("%d\n",(1+n/2)*(n/2)/2);
for(i=1;i<=n/2;i++)for(j=n;j>n-i;j--)printf("%d %d\n",i,j);
return 0;
}
