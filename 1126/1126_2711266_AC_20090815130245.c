#include <stdio.h>
#include <stdlib.h>
struct Heap{
       int value;
       int index;
}*h[25010];
int hs=0;
void hAdd(struct Heap *t){
     int now=hs;
     while(now>0&&t->value>h[(now-1)/2]->value){
       h[now]=h[(now-1)/2];
       now=(now-1)/2;
     }
     h[now]=t;
     hs++;
}
struct Heap *hGet(){
       struct Heap *rtn=h[0];
       int dest,now;
       hs--;
       now=0;
       while(now*2+1<hs){
         if(now*2+2==hs)
           dest=now*2+1;
         else if(h[now*2+1]->value>h[now*2+2]->value)
           dest=now*2+1;
         else
           dest=now*2+2;
         if(h[hs]->value>h[dest]->value)
           break;
         h[now]=h[dest];
         now=dest;
       }
       h[now]=h[hs];
       return rtn;
}
int main(){
    struct Heap *t;
    int m,n,i=0,tot[25010];
    scanf("%d",&m);
    while(1){
      scanf("%d",&tot[i]);
      if(tot[i]==-1)
        break;
      i++;
    }
    n=i;
    for(i=0;i<m-1;i++){
      t=malloc(sizeof(struct Heap));
      t->value=tot[i];
      t->index=i;
      hAdd(t);
    }
    for(i=m-1;i<n;i++){
      t=malloc(sizeof(struct Heap));
      t->value=tot[i];
      t->index=i;
      hAdd(t);
      while(1){
        t=hGet();
        if(t->index>i-m)
          break;
      }
      hAdd(t);
      printf("%d\n",t->value);
    }
}
