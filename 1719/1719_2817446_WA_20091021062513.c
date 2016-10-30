#include <stdio.h>
#include <math.h>
double min(double a,double b){
       if(a<b)return a;
       return b;
}
int main(){
    int x[4],y[4],i,j,k,l,h,m[4];
    double bv=1e100,x0,y0,x3,y3,k0,b0,k1,b1,td,t1,t2,tk,tb;
    for(i=0;i<4;i++)scanf("%d%d",&x[i],&y[i]);
    for(i=0;i<3;i++)for(j=i+1;j<4;j++){
      for(h=0;h<4;h++)m[h]=0;
      m[i]=m[j]=1;
      for(h=0;h<4;h++)if(m[h]==0)k=h;
      l=6-i-j-k;
      td=x0=y0=0;
      if(x[i]==x[j]){
        t1=abs(x[i]);
        x3=x[i];
        y3=0;
      }else if(y[i]==y[j]){
        t1=abs(y[i]);
        y3=y[i];
        x3=0;
      }else{
        k0=(double)(y[i]-y[j])/(x[i]-x[j]);
        b0=y[i]-k0*x[i];
        k1=-1/k0;
        b1=y0-k1*x0;
        x3=(b1-b0)/(k0-k1);
        y3=k0*x3+b0;
        t1=sqrt((x3-x0)*(x3-x0)+(y3-y0)*(y3-y0));
      }
      tk=k0;
      tb=b0;
      x0=x3;
      y0=y3;
      if(x[k]==x[l]){
        t2=abs(x[k]-x0);
        x3=x[k];
        y3=0;
      }else if(y[k]==y[l]){
        t2=abs(y[k]-y0);
        y3=y[k];
        x3=0;
      }else{
        k0=(double)(y[k]-y[l])/(x[k]-x[l]);
        b0=y[k]-k0*x[k];
        k1=-1/k0;
        b1=y0-k1*x0;
        x3=(b1-b0)/(k0-k1);
        y3=k0*x3+b0;
        t2=sqrt((x3-x0)*(x3-x0)+(y3-y0)*(y3-y0));
      }
      bv=min(bv,t1+t2);
      if(tk!=k0){
        x3=(b0-tb)/(tk-k0);
        y3=k0*x3+b0;
        bv=min(bv,sqrt(x3*x3+y3*y3));
      }
    }
    printf("%.5lf\n",bv);
}
