#include<iostream>
#include<cmath>
using namespace std;
int n,t,t1,s=0;
double a,a1,t1,x,y;
int main(){
int i;
cin>>t1>>a1;
if(t1==1)x=2*a1;
else if(t1==2)x=sqrt(2)*a;
else x=a;
cin>>n;
for(i=1;i<=n;i++){
cin>>t>>a;
if(t==1)y=2*a1;
else if(t==2)y=a;
else y=sqrt(3)/2*a;
if(y-0.00001<x)s++;
}
cout<<x;
}