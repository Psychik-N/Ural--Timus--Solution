#include <stdio.h>
int n,i,j,ss[2500],pm[2500]={0},b,w;
int main(){
scanf("%d",&n);
for(i=1;i<=n;i++){
scanf("%d",&ss[i]);
pm[ss[i]]=i;
}
for(i=1;i<=n;i++){
if(pm[i]==0)continue;
b=w=0;
for(j=1;j<i;j++)if(ss[j]>ss[i]&&pm[i]!=0)w++;
for(j=i+1;j<=n;j++)if(ss[j]<ss[i]&&pm[i]!=0)b++;
printf("%d %d\n",b+1,n-w);
}
}
