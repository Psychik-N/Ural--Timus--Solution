#include <stdio.h>
#include <math.h>
double p2(double a){
       return a*a;
}
int main(){
    int i,n,s=0,d=0;
    double a,b,c,x[20],y[20],r[20],ix,iy;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
    for(ix=0;ix<1.0005;ix+=0.0079)for(iy=0;iy<1.0005;iy+=0.0079){
      d++;
      for(i=0;i<n;i++)if(p2(ix-x[i])+p2(iy-y[i])<p2(r[i])){s++;break;}
    }
    printf("%lf",(double)s*100/d);
}
