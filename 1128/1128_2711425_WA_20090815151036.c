#include <stdio.h>
#include <stdlib.h>
struct Edge{
       int to;
       struct Edge *next;
};
int main(){
    struct Edge *edg[7200]={0},*t;
    int n,k,i,j,z[7200]={0},z2=0,in;
    char m[7200];
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&k);
      for(j=0;j<k;j++){
        scanf("%d",&in);
        t=malloc(sizeof(struct Edge));
        t->to=in;
        t->next=edg[i];
        edg[i]=t;
        t=malloc(sizeof(struct Edge));
        t->to=i;
        t->next=edg[in];
        edg[in]=t;
      }
    }
    for(i=1;i<=n;i++){
      k=0;
      t=edg[i];
      for(j=0;j<7200;j++)m[j]=0;
      while(t!=0){
        if(z[t->to]==z[i]&&m[t->to]==0){
          k++;
          m[t->to]=1;
        }
        t=t->next;
      }
      if(k>1){
        z[i]=1;
        z2++;
      }
    }
    for(i=1;i<=n;i++){
      k=0;
      t=edg[i];
      for(j=0;j<7200;j++)m[j]=0;
      while(t!=0){
        if(z[t->to]==z[i]&&m[t->to]==0){
          k++;
          m[t->to]=1;
        }
        t=t->next;
      }
      if(k>1){
        puts("NO SOLUTION");
        return 0;
      }
    }
    if(z2<n-z2){
      k=1;
      printf("%d\n",z2);
    }else if(z2>n-z2){
      k=0;
      printf("%d\n",n-z2);
    }else{
      k=z[1];
      printf("%d\n",z2);
    }
    for(i=1;i<=n;i++)
      if(z[i]==k)
        printf("%d ",i);
}
