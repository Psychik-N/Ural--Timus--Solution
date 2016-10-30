#include <stdio.h>
#include <math.h>
struct P{
       int x,y,id;
       double a;
}p[10010],*s[10010],*heap[10010];
void hs(int n){
     int now,hs=0,dest,i;
     for(i=0;i<n-1;i++){
       now=i;
       while(now>0){
         if(s[i]->a>=heap[(now-1)/2]->a)break;
         heap[now]=heap[(now-1)/2];
         now=(now-1)/2;
       }
       heap[now]=s[i];
     }
     hs=n-1;
     for(i=0;i<n-1;i++){
       s[i]=heap[0];
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
    int n,i,a,b,bi=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d%d",&(p[i].x),&(p[i].y));
      p[i].id=i+1;
    }
    for(i=0;i<n;i++)if(p[i].x<p[bi].x||(p[i].x==p[bi].x&&p[i].y<p[bi].y))bi=i;
    for(i=0;i<bi;i++)s[i]=&p[i];
    for(i=bi;i<n-1;i++)s[i]=&p[i+1];
    for(i=0;i<n;i++)p[i].a=atan2(p[i].y-p[bi].y,p[i].x-p[bi].x);
    hs(n);
    printf("%d %d\n",bi+1,s[n/2-1]->id);
}
