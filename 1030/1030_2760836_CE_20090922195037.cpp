#include<iomanip.h>
#include<math.h>
#include<stdio.h>
int main(){
double X1[2],X2[2],X3[2],Y1[2],Y2[2],Y3[2],X[2],Y[2],r[2],x[2],y[2],z[2],d,rd;
double pi=3.1415926535897932384626,R=3437.5;
char c[1000];
gets(c);gets(c);
int i;
for(i=1;i<=27;i++)cin>>c[0];
cin>>X1[0]>>c[0]>>X2[0]>>c[0]>>X3[0]>>c[0];
X[0]=X1[0]+X2[0]/60+X3[0]/3600;
cin>>c[0];
if(c[0]=='S')X[0]=-X[0];
cin>>c[0]>>c[0]>>c[0]>>c[0];
cin>>Y1[0]>>c[0]>>Y2[0]>>c[0]>>Y3[0]>>c[0];
Y[0]=Y1[0]+Y2[0]/60+Y3[0]/3600;
cin>>c[0];
if(c[0]=='W')Y[0]=-Y[0];
cin>>c[0]>>c[0];
for(i=1;i<=21;i++)cin>>c[0];
cin>>X1[1]>>c[0]>>X2[1]>>c[0]>>X3[1]>>c[0];
X[1]=X1[1]+X2[1]/60+X3[1]/3600;
cin>>c[0];
if(c[0]=='S')X[1]=-X[1];
if(c[0]!='S'&&c[0]!='N')while(1)i++;
cin>>c[0]>>c[0]>>c[0]>>c[0];

cin>>Y1[1]>>c[1]>>Y2[1]>>c[0]>>Y3[1]>>c[0];
Y[1]=Y1[1]+Y2[1]/60+Y3[1]/3600;
cin>>c[0];
if(c[0]=='W')Y[1]=-Y[1];
cin>>c[0]>>c[0];
for(i=0;i<=1;i++){
y[i]=R*sin(X[i]*pi/180);
r[i]=R*cos(X[i]*pi/180);
z[i]=r[i]*sin(Y[i]*pi/180);
x[i]=r[i]*cos(Y[i]*pi/180);
}
d=sqrt((x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1])+(z[0]-z[1])*(z[0]-z[1]));
rd=2*asin(d/2/R)*R+(1e-8);
cout<<"The distance to the iceberg: "
int id=rd*100;
cout<<id/100;
if(id<10)cout<<0;
cout<<id%100<<" miles."<<endl;
if(rd<100-0.005)cout<<"DANGER!";
}