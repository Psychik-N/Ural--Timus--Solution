#include <stdio.h>
#include <math.h>
struct P{
       int x,y,id;
       double a;
}p[10010],*s[10010],*heap[10010];
void hs(int n){
     int now,hs=0,dest,i,add=0;
     for(i=0;i<n+add;i++){
       if(p[i].x==0&&p[i].y==0){
         add=1;
         continue;
       }
       now=i-add;
       while(now>0){
         if(p[i].a>=heap[(now-1)/2]->a)break;
         heap[now]=heap[(now-1)/2];
         now=(now-1)/2;
       }
       heap[now]=&p[i];
     }
     hs=n;
     for(i=0;i<n;i++){
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
    int n,i,a,b,sid=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d%d",&(p[i].x),&(p[i].y));
      p[i].a=atan2(p[i].y,p[i].x);
      p[i].id=i+1;
      if(p[i].x==0&&p[i].y==0)sid=i;
    }
    if(sid==-1)hs(n);
    else hs(n-1);
    if(sid==-1){
      a=s[n/2-1]->id;
      b=s[n/2]->id;
      if(a<b)printf("%d %d",a,b);
      else printf("%d %d",b,a);
    }else printf("%d %d",sid+1,s[n/2-1]->id);
}
