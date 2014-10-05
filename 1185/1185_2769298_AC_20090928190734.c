#include <stdio.h>
#include <math.h>
#define eps (1e-9)
struct P{
       int x,y;
       double a;
}ys[1010],*p[1010],*s[1010];
double dist(double a,double b,double c,double d){
       return (a-c)*(a-c)+(b-d)*(b-d);
}
int main(){
    int n,i,j,bi,bx=20000,by=20000,sl=3,l,mi,m[1010]={0};
    double tot=0,mv;
    scanf("%d%d",&n,&l);
    for(i=0;i<n;i++){
      scanf("%d%d",&(ys[i].x),&(ys[i].y));
      if(ys[i].y<by||(ys[i].y==by&&ys[i].x<bx)){
        bx=ys[i].x;
        by=ys[i].y;
        bi=i;
      }
    }
    for(i=0;i<n;i++){
      if(i==bi)continue;
      ys[i].a=atan2(ys[i].y-by,ys[i].x-bx);
    }
    ys[bi].a=-(1e10);
    for(i=0;i<n;i++){
      mv=1e10;
      for(j=0;j<n;j++){
        if((ys[j].a<mv-eps||(fabs(ys[j].a-mv))<eps&&(mv==1e10||dist(bx,by,ys[j].x,ys[j].y)<dist(bx,by,ys[mi].x,ys[mi].y)))&&m[j]==0){
          mv=ys[j].a;
          mi=j;
        }
      }
      p[i]=&ys[mi];
      m[mi]=1;
    }
    //for(i=0;i<n;i++)printf("%d:%d %d %lf\n",i,p[i]->x,p[i]->y,p[i]->a);
    for(i=0;i<3;i++)s[i]=p[i];
    for(i=3;i<n;i++){
      start:
      if((s[sl-1]->x-p[i]->x)*(s[sl-2]->y-p[i]->y)-
         (s[sl-1]->y-p[i]->y)*(s[sl-2]->x-p[i]->x)>0){
        sl--;
        goto start;
      }
      s[sl]=p[i];
      sl++;
    }
    s[sl]=s[0];
    for(i=0;i<sl;i++)tot+=sqrt((s[i]->x-s[i+1]->x)*(s[i]->x-s[i+1]->x)+
                               (s[i]->y-s[i+1]->y)*(s[i]->y-s[i+1]->y));
    tot+=2*3.1415926535897932384633*l;
    printf("%.0lf",tot);
}
