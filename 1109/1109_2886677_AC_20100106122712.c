#include <stdio.h>
#include <stdlib.h>
struct Edge{int to;struct Edge *next;}*edg[1010]={0};
int mark[1010]={0},from[1010]={0};
int dfs(int v,int p){
struct Edge *t=edg[p];
if(mark[p]==v)return 0;
mark[p]=v;
while(t){
if(from[t->to]==0||dfs(v,from[t->to])){
from[t->to]=p;
return 1;
}
t=t->next;
}
return 0;
}
int main(){
struct Edge *t;
int m,n,i,a,b,c=0,k;
scanf("%d%d%d",&m,&n,&k);
for(i=0;i<k;i++){
scanf("%d%d",&a,&b);
t=malloc(8);
t->to=b;
t->next=edg[a];
edg[a]=t;
}
for(i=1;i<=m;i++)if(dfs(i,i))c++;
printf("%d",m+n-c);
}
