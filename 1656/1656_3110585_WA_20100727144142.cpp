#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int a[10][10],n,i,j,h[99];
int f[]={1,0,1,0,1,0,1,0,1,0};
cin>>n;
for(i=1;i<=n*n;i++)cin>>h[i];
sort(h,h+n*n);
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
a[(n+1)/2+f[i]*int(i/2)][(n+1)/2+f[j]*int(j/2)]=h[i*n+j-n];
for(i=1;i<=n;i++){
for(j=1;j<=n;j++)cout<<a[i][j]<<" ";
cout<<endl;
}
}
