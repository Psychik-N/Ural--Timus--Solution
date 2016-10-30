﻿#include <stdio.h>
#include <math.h>
struct P{
       int x,y,id;
       double a;
       long long dist;
}p[10010],*s[10010],*heap[10010];
int main(){
    int n,i,j,bi,a,b,sid=-1,at=0,mark[10010]={0};
    double bv;
    long long bd;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d%d",&(p[i].x),&(p[i].y));
      p[i].a=atan2(p[i].y,p[i].x);
      p[i].id=i+1;
      if(p[i].x==0&&p[i].y==0)sid=i;
      p[i].dist=(long long)p[i].x*p[i].x+(long long)p[i].y*p[i].y;
    }
    for(i=0;i<n;i++){
      if(i==sid)continue;
      bv=1e100;
      bd=-(long long)2000000000*2000000000;
      for(j=0;j<n;j++){
        if(mark[j]==0&&j!=sid&&(p[j].a+(1e-9)<bv||(abs(p[j].a-bv)<1e-9&&p[j].dist>bd))){
          bv=p[j].a;
          bi=j;
          bd=p[j].dist;
        }
      }
      mark[bi]=1;
      s[at]=&p[bi];
      at++;
    }
    if(sid==-1){
      a=s[n/2-1]->id;
      b=s[n/2]->id;
      if(a<b)printf("%d %d\n",a,b);
      else printf("%d %d\n",b,a);
    }else printf("%d %d\n",sid+1,s[n/2-1]->id);
}
