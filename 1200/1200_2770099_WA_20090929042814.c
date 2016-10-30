#include <stdio.h>
#define eps (1e-8)
int main(){
    int k,i,z,bi=0,bj=0,ti;
    double a,b,bv=0,tv;
    scanf("%lf%lf%d",&a,&b,&k);
      for(i=1;i<=k;i++){
        ti=(int)((a-b+2*i)/4+0.5+eps);
        if(ti<0){
          tv=b*i-(double)i*i;
          if(tv-bv>eps){
            bv=tv;
            bi=0;
            bj=i;
          }
        }else if(ti>i){
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
ti--;
        if(ti<0){
          tv=b*i-(double)i*i;
          if(tv-bv>eps){
            bv=tv;
            bi=0;
            bj=i;
          }
        }else if(ti>i){
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
ti+=2;
        if(ti<0){
          tv=b*i-(double)i*i;
          if(tv-bv>eps){
            bv=tv;
            bi=0;
            bj=i;
          }
        }else if(ti>i){
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
    printf("%.2lf\n%d %d",bv,bi,bj);
}
