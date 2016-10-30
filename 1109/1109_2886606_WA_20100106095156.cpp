#include<iostream>
using namespace std;
int n,m,k,e[3000000][3]={0},t=10000,mark[2000],from[2000]={0};
int dfs(int v){
if(mark[v])return 0;
mark[v]=1;
int myt=e[v][1];
while(myt!=0){
if(from[e[myt][0]]==0||dfs(e[myt][0])){
from[e[myt][0]]=v;
return 1;
}
myt=e[myt][1];
}
return 0;
}
int main(){
cin>>n>>m>>k;
int i,a,b,cop=0;
for(i=1;i<=k;i++){
cin>>a>>b;
e[t][0]=b;
e[t][1]=e[a][1];
e[a][1]=t;
t++;
}
for(i=1;i<=n;i++){
memset(mark,0,8000);
if(dfs(i))cop++;
}
cout<<m+n-cop;
}
