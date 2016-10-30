#include <stdio.h>
#include <stdlib.h>
struct Edge{
       int to;
       struct Edge *next;
}*edg[1010]={0};
int mark[1010]={0};
int f(int p,int c){
    struct Edge *w=edg[p];
    int v=c,a,zd=0;
    while(w!=0){
      if(mark[w->to]==0){
      mark[w->to]=1;
      a=f(w->to,!c);
      if(c==0){
        if(a!=0&&v==0)v=w->to;
      }else if(v!=0){
        if(a==0)v=0;
        else if(zd==0)zd=w->to;
      }
      }
      w=w->next;
    }
    if(c==1&&zd!=0)return zd;
    return v;
}
int main(){
    int n,k,i,a,b;
    struct Edge *t;
    scanf("%d%d",&n,&k);
    for(i=1;i<n;i++){
      scanf("%d%d",&a,&b);
      t=malloc(8);
      t->to=b;
      t->next=edg[a];
      edg[a]=t;
      t=malloc(8);
      t->to=a;
      t->next=edg[b];
      edg[b]=t;
    }
    mark[k]=1;
    a=f(k,0);
    if(a!=0)printf("First player wins flying to airport %d",a);
    else printf("First player loses");
}
