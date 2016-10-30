#include <stdio.h>
int main(){
int n,i,j,ss[2500],pm[2500],b,w;
scanf("%d",&n);
for(i=1;i<=n;i++){
scanf("%d",&ss[i]);
pm[ss[i]]=i;
}
for(i=1;i<=n;i++){
b=w=0;
for(j=1;j<i;j++)if(ss[j]>ss[i])w++;
for(j=i+1;j<=n;j++)if(ss[j]<ss[i])b++;
printf("%d %d\n",b+1,n-w);
}
}
