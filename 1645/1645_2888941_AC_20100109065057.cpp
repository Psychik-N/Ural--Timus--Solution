#include<iostream>
using namespace std;
int n,a[2500],t,i,j,b,w;
int main(){
cin>>n;
for(i=1;i<=n;i++){
cin>>t;
a[t]=i;
}
for(i=1;i<=n;i++){
b=0;w=0;
for(j=1;j<=n;j++){
if(j>i&&a[j]<a[i])b++;
if(j<i&&a[j]>a[i])w++;
}
cout<<b+1<<" "<<n-w<<endl;
}
}