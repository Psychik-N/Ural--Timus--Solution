#include<iostream>
#include<algorithm>
using namespace std;
long long x[110000],y[110000],n;
long long s=0;
int main(){
cin>>n;
long long i;
for(i=1;i<=n;i++)cin>>x[i]>>y[i];
sort(x+1,x+n+1);
sort(y+1,y+n+1);
for(i=1;i<n;i++)s+=(x[i+1]-x[i])*i*(n-i);
for(i=1;i<n;i++)s+=(y[i+1]-y[i])*i*(n-i);
cout<<s*2/(n*(n-1));
}