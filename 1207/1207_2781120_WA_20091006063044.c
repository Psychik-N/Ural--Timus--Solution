#include <stdio.h>
#include <math.h>
struct P{
       int x,y,id;
       double a;
}p[10010],*s[10010],*heap[10010];
void hs(int n){
     int now,hs=0,dest,i;
     for(i=1;i<n;i++){
       now=i-1;
       while(now>0){
         if(p[i].a>=heap[(now-1)/2]->a)break;
         heap[now]=heap[(now-1)/2];
         now=(now-1)/2;
       }
       heap[now]=&p[i];
     }
     hs=n-1;
     for(i=1;i<n;i++){
       s[i-1]=heap[0];
       hs--;
       now=0;
       while(now*2+1<hs){
         if(now*2+2==hs)dest=now*2+1;
         else if(heap[now*2+1]<heap[now*2+2])dest=now*2+1;
         else dest=now*2+2;
        if(heap[hs]->a<=heap[dest]->a)break;
         heap[now]=heap[dest];
         now=dest;
       }
       heap[now]=heap[hs];
     }
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d%d",&(p[i].x),&(p[i].y));
      p[i].a=atan2(p[i].y-p[0].y,p[i].x-p[0].x);
      p[i].id=i+1;
    }
    hs(n);
    printf("1 %d\n",s[n/2-1]->id);
}
