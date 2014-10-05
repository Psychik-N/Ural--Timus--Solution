#include<stdio.h>
int n,m,k[100],f[11000];
int go(int v){
int i,cop=0;
if(v==0)return 1;
if(f[v]!=-1)return f[v];
for(i=1;i<=m;i++)
if(v-k[i]>=0&&go(v-k[i])==0){cop=1;break;}
f[v]=cop;
return cop;
}
int main(){
int i;
scanf("%d%d",&n,&m);
for(i=0;i<=n;i++)f[i]=-1;
for(i=1;i<=m;i++)scanf("%d",&k[i]);
printf("%d",2-go(n));
return 0;
}