#include <stdio.h>
int main(){
int n,i;
scanf("%d",&n);
printf("%d\n",n*2);
for(i=1;i<=n;i++)printf("%d ",i);
for(i=n;i>=1;i--)printf("%d ",i);
return 0;
}
