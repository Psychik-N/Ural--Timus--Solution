#include <stdio.h>
#include <math.h>
struct P{
       int x,y,id;
       double a;
}p[10010],*s[10010],*heap[10010];
long long multi(struct P *p0,struct P *p1,struct P *p2){
     return (long long)(p1->x-p0->x)*(p2->y-p0->y)-(long long)(p2->x-p0->x)*(p1->y-p0->y);
}
void hs(int n,struct P *p0){
     int now,hs=0,dest,i;
     for(i=0;i<n-1;i++){
       now=i;
       while(now>0){
         if(multi(p0,s[i],heap[(now-1)/2])>=0)break;
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
         else if(multi(p0,heap[now*2+1],heap[now*2+2])<0)dest=now*2+1;
         else dest=now*2+2;
         if(multi(p0,heap[hs],heap[dest])<=0)break;
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
    for(i=0;i<n;i++)if(p[i].x<p[bi].x)bi=i;
    for(i=0;i<bi;i++)s[i]=&p[i];
    for(i=bi;i<n-1;i++)s[i]=&p[i+1];
    for(i=0;i<n;i++)p[i].a=atan2(p[i].y-p[bi].y,p[i].x-p[bi].x);
    hs(n,&p[bi]);
    printf("%d %d\n",bi+1,s[n/2-1]->id);
}
