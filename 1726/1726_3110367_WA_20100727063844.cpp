#include<iostream>
#include<algorithm>
using namespace std;
int x[110000],y[110000],n,s=0;
int main(){
cin>>n;
int i;
for(i=1;i<=n;i++)cin>>x[i]>>y[i];
sort(x,x+n);
sort(y,y+n);
for(i=1;i<n;i++)s+=(x[i+1]-x[i])*i*(n-i);
for(i=1;i<n;i++)s+=(y[i+1]-y[i])*i*(n-i);
cout<<s/(n*(n-1));
}