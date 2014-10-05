#include <stdio.h>
int a[1001];
int main(){
int bv=0,bi,n,i;
scanf("%d",&n);
for(i=1;i<=n;i++)scanf("%d",a+i);
for(i=2;i<n;i++)if(a[i-1]+a[i]+a[i+1]>bv){
bv=a[i-1]+a[i]+a[i+1];
bi=i;
}
printf("%d %d",bv,bi);
return 0;
}