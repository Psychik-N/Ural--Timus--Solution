#include <stdio.h>
struct P{
       double x,y;
       int id;
}ys[1010],*p[1010];
int up(struct P *a,struct P *b,struct P *c){
    if(b==c)return 1;
    if(a->y==b->y)return c->y>a->y;
    if(a->x==c->x)return c->y>a->y;
    if(b->x==c->x)return c->y>b->y;
    if(a->y<b->y)return c->y+(1e-9)>(c->x-a->x)*(b->y-a->y)/(b->x-a->x)+a->y;
    return c->y+(1e-9)>(b->x-c->x)*(a->y-b->y)/(b->x-a->x)+b->y;
}
int main(){
    int n,i,j,w1=0,w2=0,mi,mark[1010]={0},from[1010],t;
    double mv;
    scanf("%lf%lf%d",&(ys[0].x),&(ys[0].y),&n);
    ys[0].id=0;
    for(i=1;i<=n;i++)
      scanf("%lf%lf%d",&(ys[i].x),&(ys[i].y),&(ys[i].id));
    for(i=0;i<=n;i++){
      mv=1e100;
      for(j=0;j<=n;j++){
        if(mark[j]==0&&ys[j].x<mv){
          mv=ys[j].x;
          mi=j;
        }
      }
      p[i]=&ys[mi];
      mark[mi]=1;
    }
    for(i=1;i<=n;i++){
      if(t=up(p[0],p[n],p[i])){
        from[i]=w1;
        w1=i;
      }else{
        from[w2]=i;
        w2=i;
      }
    }
    from[w2]=n;
    for(i=0;i<=n;i++)if(p[i]->id==0)break;
    w1=i;
    do{
         printf("%d\n",p[w1]->id);
         w1=from[w1];
    }while(w1!=i);
    printf("%d",p[i]->id);
}
