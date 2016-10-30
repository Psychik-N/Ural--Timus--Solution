#include<iostream>
#include<math.h>
using namespace std;
int main(){
long long n,b,bv=10000000,i,a;
cin>>n;
if(n==1)cout<<3;
else if(n==2)cout<<5;
else{
for(i=1;i<=n;i++){
a=n-(i*i)%n;
if(a<bv){bv=a;b=i;}
}
cout<<2*n-b*b;
}
}