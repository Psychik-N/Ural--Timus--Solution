#include <stdio.h>
int main(){
int s=0,i,n;
scanf("%d",&n);
if(n<1)
for(i=1;i>=n;i--)
s+=i;
else
for(i=1;i<=n;i++)
s+=i;
printf("%d",s);
}
