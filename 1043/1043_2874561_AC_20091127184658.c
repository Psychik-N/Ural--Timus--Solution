#include <stdio.h>
#include <math.h>
#define eps (1e-4)
#define mpi 3.14159265358979323846
struct Line{double k,b;int t;}l[2];
double mmin(double a,double b){
if(a<b)return a;
return b;
}
double mmax(double a,double b){
if(a>b)return a;
return b;
}
void js(int x1,int x2,int y1,int y2,int xb){
     if(y1!=y2){
       l[xb].t=0;
       l[xb].k=-(double)(x2-x1)/(y2-y1);
       l[xb].b=(y1+y2-l[xb].k*(x1+x2))/2;
     }else{
       l[xb].t=1;
       l[xb].b=(double)(x1+x2)/2;
     }
}
int on(double sa,double ea,int at,double ta){
    if(at==0)return ta>sa&&ta<ea;
    return !on(sa,ea,0,ta);
}
int main(){
    int x[3],y[3],i,iu,id,ir,il,at;
    double rx,ry,lp,rp,up,dp,sa,ea,r,t;
    for(i=0;i<3;i++)scanf("%d%d",&x[i],&y[i]);
    for(i=0;i<2;i++)js(x[i],x[2],y[i],y[2],i);
    if(l[0].t==0&&l[1].t==0)
      rx=(l[1].b-l[0].b)/(l[0].k-l[1].k);
    else if(l[0].t==1)
      rx=l[0].b;
    else
      rx=l[1].b;
    ry=(l[0].t==0?l[0].k*rx+l[0].b:l[1].k*rx+l[1].b);
    lp=mmin(x[0],x[1]);
    rp=mmax(x[0],x[1]);
    dp=mmin(y[0],y[1]);
    up=mmax(y[0],y[1]);
    sa=atan2(y[0]-ry,x[0]-rx);
    ea=atan2(y[1]-ry,x[1]-rx);
    if(sa>ea){t=sa;sa=ea;ea=t;}
    if(on(sa,ea,0,atan2(y[2]-ry,x[2]-rx)))at=0;
    else at=1;
    r=sqrt((x[0]-rx)*(x[0]-rx)+(y[0]-ry)*(y[0]-ry));
    if(on(sa,ea,at,mpi/2))up=ry+r;
    if(on(sa,ea,at,-mpi))lp=rx-r;
    if(on(sa,ea,at,-mpi/2))dp=ry-r;
    if(on(sa,ea,at,0))rp=rx+r;
    iu=(int)(floor(up-eps)+1);
    il=(int)(floor(lp+eps));
    id=(int)(floor(dp+eps));
    ir=(int)(floor(rp-eps)+1);
    printf("%d",(iu-id)*(ir-il));
}
