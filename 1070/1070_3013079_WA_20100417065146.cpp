#include<iostream>
using namespace std;
int main(){
float a,b;
int x,y,m,n;
cin>>a>>b;
x=int(a)*60+(a-int(a))*100;
y=int(b)*60+(b-int(b))*100;
m=y+1440-x;
if(m>360)m-=1440;
cin>>a>>b;
x=int(a)*60+(a-int(a))*100;
y=int(b)*60+(b-int(b))*100;
n=y+1440-x;
if(n>360)n-=1440;
cout<<(n-m+15)/60/2;
}