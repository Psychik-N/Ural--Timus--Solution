#include<math.h>
#include<stdio.h>
double x[4],y[4],z[4];
double d(int i,int j){
return sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)+pow(z[i]-z[j],2));
}
int main(){
int i;
double a,b,c,ca,cb,dis,t,s,r,temp;
double n1,n2,m1,m2,o1,o2,p1,p2,w;
for(i=1;i<=3;i++)scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
scanf("%lf",&r);
a=d(2,3);
b=d(1,3);
c=d(2,1);
if(c<0.00001){cout<<0;return 0;}
ca=(pow(b,2)+pow(c,2)-pow(a,2))/2/b/c;
cb=(pow(a,2)+pow(c,2)-pow(b,2))/2/a/c;
dis=b*sqrt(1-ca*ca);
if(ca<=0||cb<=0||dis>=r)printf("%.2lf",c);
else{
t=acos(dis/r*0.999999);
s=sqrt(r*r-dis*dis);
n1=b*ca-s;
n2=a*cb-s;
m1=sqrt(n1*(n1+2*s));
m2=sqrt(n2*(n2+2*s));
o1=atan(m1/r);
o2=atan(m2/r);
p1=acos(dis/b*0.999999);
p2=acos(dis/a*0.999999);
w=p1+p2-o1-o2;
printf("%.2lf",m1+m2+r*w);
}
}