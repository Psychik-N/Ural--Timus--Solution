#include <stdio.h>
#include <stdlib.h>
struct Edge{
       int to;
       struct Edge *next;
}*edg[1010]={0};
int mark[1010]={0};
int f(int p,int c){
    struct Edge *w=edg[p];
    int v=c,a;
    while(w!=0){
      if(mark[w->to]==1)continue;
      mark[w->to]=1;
      a=f(w->to,!c);
      if(c==0)if(a!=0)v=a;
      else if(v!=0)v=a;
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
    a=f(k,0);
    if(a!=0)printf("First player wins flying to airport %d",a);
    else printf("First player loses");
}
