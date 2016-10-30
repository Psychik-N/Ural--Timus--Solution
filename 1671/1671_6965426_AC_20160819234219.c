#include <stdio.h>
int p[1000001];
int ex[1000001],ey[1000001];
int o[1000001],mark[1000001]={0};
int ob[1000001],ol=0;
int Find(int x){
    if(p[x]==x)return x;
    return p[x]=Find(p[x]);
}
void Union(int x,int y){
    int xr=Find(x),yr=Find(y);
    p[xr]=yr;
}
int main(){
    int n,k,m,i,cnt;
    scanf("%d%d",&n,&m);
    cnt=n;
    for(i=1;i<=n;i++)p[i]=i;
    for(i=1;i<=m;i++)scanf("%d%d",ex+i,ey+i);
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        scanf("%d",o+i);
        mark[o[i]]=1;
    }
    for(i=1;i<=m;i++)if(mark[i]==0){
        if(Find(ex[i])!=Find(ey[i]))cnt--;
        Union(ex[i],ey[i]);
    }
    for(i=k;i>=1;i--){
        ob[ol++]=cnt;
        if(Find(ex[o[i]])!=Find(ey[o[i]]))cnt--;
        Union(ex[o[i]],ey[o[i]]);
    }
    while(ol-->0)printf("%d ",ob[ol]);
    return 0;
}
