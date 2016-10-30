#include <stdio.h>
#include <stdlib.h>
struct Edge{int to;struct Edge *next;}*edg[1010]={0};
int mark[1010]={0},from[1010]={0};
int ms(){
char c;
int s;
do{
c=getchar();
}while(c<48||c>57);
s=c-48;
while(1){
c=getchar();
if(c<48||c>57)break;
s=s*10+c-48;
}
return s;
}
int dfs(int v,int p){
struct Edge *t=edg[p];
mark[p]=v;
while(t){
if(from[t->to]==0||mark[p]!=v&&dfs(v,from[t->to])){
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
m=ms();
n=ms();
k=ms();
for(i=0;i<k;i++){
a=ms();
b=ms();
t=new Edge();
t->to=b;
t->next=edg[a];
edg[a]=t;
}
for(i=1;i<=m;i++)if(mark[i]==0)if(dfs(i,i))c++;
printf("%d",m+n-c);
}

