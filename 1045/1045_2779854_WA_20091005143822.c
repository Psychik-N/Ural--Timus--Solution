#include <stdio.h>
#include <stdlib.h>
struct Edge{
       int to;
       struct Edge *next;
}*edg[1010]={0};
int mark[1010]={0},from[1010]={0};
int f(int p,int c){
    struct Edge *w=edg[p];
    int v=c,a;
    while(w!=0){
      if(mark[w->to]==0){
      mark[w->to]=1;
      a=f(w->to,!c);
      if(c==0){
        if(a!=0&&from[p]==0)from[p]=w->to;
        if(a!=0)v=1;
      }else if(v!=0){
        if(a==0)v=0;
        else if(from[p]==0)from[p]=w->to;
      }
      }
      w=w->next;
    }
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
    if(a!=0)printf("First player wins flying to airport %d",from[k]);
    else printf("First player loses");
}
