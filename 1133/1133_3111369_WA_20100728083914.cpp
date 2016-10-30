#include<iostream>
using namespace std;
int main(){
long long a[5000],i,j,s=-3000000000,e=3000000000,m,k,n;
cin>>i;
cin>>a[i+2500]>>j;
cin>>a[j+2500]>>n;
if(i>j)swap(i,j);
while(s<e){
if(j=i+1)break;
m=(s+e)/2;
a[i+2501]=m;
for(k=i+2;k<=j-1;k++)a[k+2500]=a[k+2499]+a[k+2498];
if(a[j+2498]+a[j+2499]<a[j]+2500)s=m+1;
else if(a[j+2498]+a[j+2499]>a[j+2500])e=m-1;
else break;
}
if(n<=i)for(k=i+2499;k>=n+2500;k--)a[k]=a[k+2]-a[k+1];
if(n>=j)for(k=j+2501;k<=n+2500;k++)a[k]=a[k-2]+a[k-1];
cout<<a[n+2500];
if(m<1000)while(1);
}