#include <stdio.h>
#include <stdlib.h>
struct Edge{
int to;
struct Edge *next;
};
int main(){
struct Edge *edg[10001]={0},*t,*w;
int n,i,j,in,on=0,ql[2]={0},q[2][10001],f[10001]={0},l,l2,c=0;
scanf("%d",&n);
for(i=2;i<=n;i++){
scanf("%d",&in);
t=malloc(sizeof(struct Edge));
t->to=i;
t->next=edg[in];
edg[in]=t;
t=malloc(sizeof(struct Edge));
t->to=in;
t->next=edg[i];
edg[i]=t;
}
q[0][0]=1;
ql[0]=1;
while(ql[on]!=0){
l=q[on][0];
ql[!on]=0;
for(i=0;i<ql[on];i++){
w=edg[q[on][i]];
while(w!=0){
if(m[w->to]==0){
m[w->to]=1;
q[!on][ql[!on]]=w->to;
ql[!on]++;
}
w=w->next;
}
}
on=!on;
}
on=ql[1]=0;
q[0][0]=l;
ql[0]=1;
for(i=1;i<=n;i++)m[i]=0;
while(ql[on]!=0){
c++;
l2=q[on][0];
ql[!on]=0;
for(i=0;i<ql[on];i++){
w=edg[q[on][i]];
while(w!=0){
if(m[w->to]==0){
m[w->to]=q[on][i];
q[!on][ql[!on]]=w->to;
ql[!on]++;
}
w=w->next;
}
}
on=!on;
}
for(i=0;i<c/2;i++)l2=from[l2];
printf("%d",l2);
if(c%2==1)printf(" %d",from[l2]);
}
