#include<iostream>
using namespace std;
int n,m,k[100],f[11000];
int go(int v){
if(f[v]!=-1)return f[v];
if(v==0)return 0;
int i,cop=1;
for(i=1;i<=m;i++)
if(v>=k[i])cop=cop&go(v-k[i]);
cop=!cop;
f[v]=cop;
return cop;
}
int main(){
cin>>n>>m;
int i;
for(i=0;i<=n;i++)f[i]=-1;
for(i=1;i<=m;i++)cin>>k[i];
cout<<2-go(n);
}