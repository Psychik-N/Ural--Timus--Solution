#include<iostream>
using namespace std;
int main(){
float a,b;
int x,y,m,n,t;
cin>>a>>b;
x=int(a)*60+(a-int(a))*100;
y=int(b)*60+(b-int(b))*100;
m=y-x;
cin>>a>>b;
x=int(a)*60+(a-int(a))*100;
y=int(b)*60+(b-int(b))*100;
n=y-x;
while(n<0)n+=1440;
t=(n-m+15)/2/60;
while(t>5)t-=12;
while(t<-5)t+=12;
if(t>0)cout<<t;
else cout<<-t;
}