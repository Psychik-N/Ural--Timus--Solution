#include<iostream>
#include<math.h>
using namespace std;
double x[210000],y[210000],t=0,tt;
int n;
double dis(double a,double b,double c,double d){
    return sqrt(pow(a-c,2)+pow(b-d,2));
}
int main(){
    cin>>n;
    int i;
    double a,b,c;
    for(i=1;i<=n;i++)cin>>x[i]>>y[i];
    x[i]=x[1];y[i]=y[1];x[i+1]=x[2];y[i+1]=y[2];
    for(i=2;i<=n+1;i++){
        a=dis(x[i-1],y[i-1],x[i],y[i]);
        b=dis(x[i+1],y[i+1],x[i],y[i]);
        c=dis(x[i+1],y[i+1],x[i-1],y[i-1]);
        tt=acos((a*a+b*b-c*c)/(2*a*b));
        if((x[i+1]-x[i-1])*(y[i]-y[i-1])-(y[i+1]-y[i-1])*(x[i]-x[i-1])<0)tt=-tt;
        t+=tt;
    }
    if(t>0)cout<<"cw";
    else cout<<"ccw";
    system("pause");
}