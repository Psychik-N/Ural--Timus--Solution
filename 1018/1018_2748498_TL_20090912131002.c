#include <stdio.h>
#include <stdlib.h>
int mark[600]={0};
struct Edge{int to,len;struct Edge *next;}*edg[600]={0};
struct TreeNode{int left,llen,right,rlen;}tn[600];
int max(int a,int b){
if(a>b)return a;
return b;
}
void dfs(int p){
int stat=0;
struct Edge *t=edg[p];
mark[p]=1;
while(t){
if(mark[t->to]==0){
if(stat==0){
tn[p].left=t->to;
tn[p].llen=t->len;
}else{
tn[p].right=t->to;
tn[p].rlen=t->len;
}
stat++;
dfs(t->to);
}
t=t->next;
}
}
int go(int p,int left){
int bv,i;
if(left==0)return 0;
if(tn[p].left==0)return 0;
if(tn[p].right==0)return tn[p].llen+go(tn[p].left,left-1);
bv=max(go(tn[p].left,left-1)+tn[p].llen,go(tn[p].right,left-1)+tn[p].rlen);
for(i=1;i<left;i++)bv=max(bv,tn[p].llen+tn[p].rlen+go(tn[p].left,i-1)+go(tn[p].right,left-i-1));
return bv;
}
int main(){
int m,n,i,a,b,l;
struct Edge *t;
for(i=0;i<600;i++)tn[i].left=tn[i].right=0;
scanf("%d%d",&n,&m);
for(i=1;i<n;i++){
scanf("%d%d%d",&a,&b,&l);
t=malloc(12);
t->to=b;
t->len=l;
t->next=edg[a];
edg[a]=t;
t=malloc(12);
t->to=a;
t->len=l;
t->next=edg[b];
edg[b]=t;
}
dfs(1);
printf("%d",go(1,m));
}
