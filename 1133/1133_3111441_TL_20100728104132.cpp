#include<iostream>
using namespace std;
int main(){
long long a[5000],i,j,k,n,f[5000];
f[1]=1;
f[2]=1;
for(i=3;i<=4500;i++){
f[i]=f[i-1]+f[i-2];
if(f[i]>3000000000)f[i]=3000000000;
}
cin>>i;
cin>>a[i+2500]>>j;
cin>>a[j+2500]>>n;
if(i>j)swap(i,j);
if(j-i>1){
a[i+2501]=(a[j+2500]-f[j-i-1]*a[i+2500])/f[j-i];
}
if(n<i)for(k=i+2499;k>=n+2500;k--)a[k]=a[k+2]-a[k+1];
if(n>j)for(k=i+2502;k<=n+2500;k++)a[k]=a[k-2]+a[k-1];
cout<<a[n+2500];
if(a[2501]==3)while(1);
}

/*
I 1 0
1 0 1
2 1 1
3 1 2
4 2 3
*/