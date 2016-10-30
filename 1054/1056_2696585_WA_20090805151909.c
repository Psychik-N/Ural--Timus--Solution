#include <stdio.h>
#include <stdlib.h>
struct Edge{
       int to;
       struct Edge *next;
};
int main(){
    struct Edge *edg[10001]={0},*w;
    int n,i,j,c[10001]={0},ca,t,p[10001],pl,m[10001]={0};
    scanf("%d",&n);
    ca=n;
    for(i=2;i<=n;i++){
      scanf("%d",&t);
      w=malloc(sizeof(struct Edge));
      w->to=t;
      w->next=edg[i];
      edg[i]=w;
      w=malloc(sizeof(struct Edge));
      w->to=i;
      w->next=edg[t];
      edg[t]=w;
      c[i]++;
      c[t]++;
    }
    while(ca>2){
      pl=0;
      for(i=1;i<=n;i++){
        if(c[i]!=1)continue;
        p[pl]=i;
        pl++;
      }
      for(i=0;i<pl;i++){
        ca--;
        w=edg[p[i]];
        while(w!=0){
          c[w->to]--;
          w=w->next;
        }
        m[p[i]]=1;
      }
    }
    for(i=1;i<=n;i++)if(m[i]==0)printf("%d ",i);
}
