#include <iostream>
#include <math.h>
using namespace std;
int main(){
int a,b,c,n,sum,tn,i;
cin>>a>>c>>b;
for(n=1;n<=10000;n++){
sum=0;
for(i=1;i<=sqrt(double(n))+(1e-9);i++)if(n%i==0)sum++;
if(sum!=a)continue;
tn=n+b;sum=0;
for(i=1;i<=sqrt(double(tn))+(1e-9);i++)if(tn%i==0)sum++;
if(sum!=c)continue;
cout<<tn;
return 0;
}
cout<<0;
}