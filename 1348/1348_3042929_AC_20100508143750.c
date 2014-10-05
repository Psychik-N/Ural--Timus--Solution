#include <stdio.h>
#include <math.h>
double min=1e100,max=0;
double p2(double x){return x*x;}
double upd(double x){
x=fabs(x);
if(x>max)max=x;
if(x<min)min=x;
}
int main(){
double x1,y1,x2,y2,x3,y3,k1,k2,b1,b2,x,y,l;
scanf("%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&l);
upd(sqrt(p2(x3-x1)+p2(y3-y1)));
upd(sqrt(p2(x3-x2)+p2(y3-y2)));
if(x1==x2){if((y3-y1)*(y3-y2)<=0)upd(x3-x1);}
else if(y1==y2){if((x3-x1)*(x3-x2)<=0)upd(y3-y1);}
else{
k1=(y1-y2)/(x1-x2);
k2=-1/k1;
b1=y1-k1*x1;
b2=y3-k2*x3;
x=(b2-b1)/(k1-k2);
y=k1*x+b1;
if((x-x1)*(x-x2)<=0)upd(sqrt(p2(x3-x)+p2(y3-y)));
}
printf("%.2lf\n",min<l?0:min-l);
printf("%.2lf\n",max<l?0:max-l);
}
