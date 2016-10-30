#include<iostream>
#include <stdio.h>
#include<math.h>
using namespace std;
int p[2600],v[2600],h[60]={0},m,n,ans=0;
double x[2600][60];
int pd(int a,int b){
int i;double bs=0;
for(i=1;i<=n;i++){
if(x[a][i]==0&&x[b][i]==0)continue;
if(x[a][i]==0||x[b][i]==0)return 0;
if(bs==0)bs=x[a][i]/x[b][i];
else{
if(fabs(bs-x[a][i]/x[b][i])>0.0001)return 0;
}
}
return 1;
}

int main(){
int i,j;
scanf("%d%d",&m,&n);
for(i=1;i<=m;i++)for(j=1;j<=n;j++)scanf("%d",&x[i][j]);
for(i=1;i<=m;i++)scanf("%d",&v[i]);
for(i=1;i<=m;i++)p[i]=i;
for(i=1;i<=m;i++)for(j=1;j<=m;j++)if(v[p[i]]<v[p[j]])swap(p[i],p[j]);
for(i=1;i<=m;i++){
for(j=1;j<=n;j++){
if(h[j]==0){h[j]=p[i];goto nxt;}
else{
if(pd(p[i],h[j])){
if(v[p[i]]<v[h[j]])h[j]=p[i];
goto nxt;;
}
}
}
goto end;
nxt:;
}
end:
for(i=1;i<=n;i++)ans+=v[h[i]];
cout<<ans<<endl;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(h[i]<h[j])swap(h[i],h[j]);
for(i=1;i<=n;i++)cout<<h[i]<<endl;
}
