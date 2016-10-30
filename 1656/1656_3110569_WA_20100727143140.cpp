#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int a[10][10],n,i,j,h[99];
cin>>n;
for(i=1;i<=n*n;i++)cin>>h[i];
sort(h,h+n*n);
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
a[(i+(n-3)/2)%n+1][(j+(n-3)/2)%n+1]=h[i*n+j-n];
for(i=1;i<=n;i++){
for(j=1;j<=n;j++)cout<<a[i][j]<<" ";
cout<<endl;
}
}
