#include <stdio.h>
#define eps (1e-8)
int main(){
    int k,i,z,bi=0,bj=0,ti;
    double a,b,bv=0,tv;
    scanf("%lf%lf%d",&a,&b,&k);
    /*if(a<=eps&&b<=eps)puts("0.00\n0 0");
    else if(a>eps&&b<=eps){
      ti=(int)(a/2+0.5+eps);
      if(ti<=k){
        tv=-(double)ti*ti+a*ti;
        if(tv>eps)printf("%.2lf\n%d 0",tv,ti);
        else puts("0.00\n0 0");
      }else{
        tv=-(double)k*k+a*k;
        if(tv>eps)printf("%.2lf\n%d 0",tv,k);
        else puts("0.00\n0 0");
      }
    }else if(a<=eps&&b>eps){
      ti=(int)(b/2+0.5+eps);
      if(ti<=k){
        tv=-ti*(double)ti+b*ti;
        if(tv>eps)printf("%.2lf\n0 %d",tv,ti);
        else puts("0.00\n0 0");
      }else{
        tv=-k*k+b*k;
        if(tv>eps)printf("%.2lf\n0 %d",tv,k);
        else puts("0.00\n0 0");
      }
    }else{*/
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
      }
    printf("%.2lf\n%d %d",bv,bi,bj);
//    }
}
