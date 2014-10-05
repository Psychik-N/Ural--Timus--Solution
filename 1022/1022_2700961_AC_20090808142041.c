#include <stdio.h>
#include <stdlib.h>
struct Edge{
       int to;
       struct Edge *next;
};
int main(){
    int n,i,t,count[101]={0},stk[101],sl=0;
    struct Edge *edg[101]={0},*w;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      while(1){
        scanf("%d",&t);
        if(t==0)break;
        count[t]++;
        w=malloc(sizeof(struct Edge));
        w->to=t;
        w->next=edg[i];
        edg[i]=w;
      }
    }
    for(i=1;i<=n;i++){
      if(count[i]==0){
        stk[sl]=i;
        sl++;
      }
    }
    while(sl>0){
      sl--;
      t=stk[sl];
      printf("%d ",t);
      w=edg[t];
      while(w!=0){
        count[w->to]--;
        if(count[w->to]==0){
          stk[sl]=w->to;
          sl++;
        }
        w=w->next;
      }
    }
}
