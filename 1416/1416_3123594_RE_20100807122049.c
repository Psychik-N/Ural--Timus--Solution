#include <stdio.h>
#include <stdlib.h>
struct Edge{
int a,b,w;
}edg[30000];
int n,m,me[30000]={0},h[600];
int cmp(const struct Edge *a,const struct Edge *b){
return a->w-b->w;
}
void zip(int p){
int t,w=p,b;
while(h[w]!=w)w=h[w];
b=w;
w=p;
while(w!=b){
t=h[w];
h[w]=b;
w=t;
}
}
void link(int a,int b){
h[h[a]]=b;
}
int find(int a){
zip(a);
return h[a];
}
int k(int f){
int i,r=0,b=0;
for(i=0;i<600;i++)h[i]=i;
for(i=0;i<m;i++)if(me[i]!=-1&&find(edg[i].a)!=find(edg[i].b)){
link(edg[i].a,edg[i].b);
r+=edg[i].w;
if(f)me[i]=1;
if(++b==n-1)return r;
}
return 2000000000;
}
int main(){
int i,t,bv=2000000000,a1;
scanf("%d%d",&n,&m);
for(i=0;i<m;i++)scanf("%d%d%d",&(edg[i].a),&(edg[i].b),&(edg[i].w));
qsort(edg,m,12,cmp);
printf("Cost: %d\n",a1=k(1));
for(i=0;i<m;i++)if(me[i]){
me[i]=-1;
t=k(0);
if(t<bv)bv=t;
if(t==a1)break;
me[i]=1;
}
if(bv==2000000000)bv=-1;
printf("Cost: %d\n",bv);
}
