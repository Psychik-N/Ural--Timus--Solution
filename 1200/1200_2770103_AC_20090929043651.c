#include <stdio.h>
#define eps (1e-8)
int main(){
    int k,i,z,bi=0,bj=0,ti,tt;
    double a,b,bv=0,tv;
    scanf("%lf%lf%d",&a,&b,&k);
      for(i=0;i<=k;i++){
        tt=(int)((a-b+2*i)/4+0.5+eps);
for(ti=tt-100;ti<tt+100;ti++){
        if(ti<=0){
          tv=b*i-(double)i*i;
          if(tv-bv>eps){
            bv=tv;
            bi=0;
            bj=i;
          }
        }else if(ti>=i){
          tv=a*i-(double)i*i;
          if(tv-bv>eps){
            bv=tv;
            bi=i;
            bj=0;
          }
        }else{
          tv=a*ti+b*(i-ti)-(double)ti*ti-(double)(i-ti)*(i-ti);
          if(tv-bv>eps){
            bv=tv;
            bi=ti;
            bj=i-ti;
          }
        }
}

      }
    printf("%.2lf\n%d %d",bv,bi,bj);
}
