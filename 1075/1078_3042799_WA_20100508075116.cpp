#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
double x[4],y[4],z[4];
double d(int i,int j){
return sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)+pow(z[i]-z[j],2));
}
int main(){
int i;
double a,b,c,ca,cb,dis,t,s,r;
for(i=1;i<=3;i++)cin>>x[i]>>y[i]>>z[i];
cin>>r;
a=d(2,3);
b=d(1,3);
c=d(2,1);
ca=(pow(b,2)+pow(c,2)-pow(a,2))/2/b/c;
cb=(pow(a,2)+pow(c,2)-pow(b,2))/2/a/b;
dis=b*ca;
if(ca<=0||cb<=0||dis>=r)printf("%.2lf",c);
else{
t=acos(dis/r);
s=sqrt(r*r-dis*dis);
printf("%.2lf",c-2*s+2*t*r);
}
}