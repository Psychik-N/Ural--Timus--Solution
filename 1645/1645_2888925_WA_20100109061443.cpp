#include <stdio.h>
int main(){
int n,a[2500],t,i,j,b[2500]={0},w[2500]={0};
scanf("%d",&n);
for(i=1;i<=n;i++){
scanf("%d",&t);
a[t]=i;
}
for(i=1;i<=n;i++){
for(j=i+1;j<=n;j++)if(a[j]<a[i])b[i]++;
for(j=1;j<i;j++)if(a[j]>a[i])w[i]++;
printf("%d %d\n",b[i]+1,n-w[i]);
}
}