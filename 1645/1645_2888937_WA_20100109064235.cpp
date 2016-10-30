#include<iostream>
using namespace std;
int main(){
int n,a[2500],t,i,j,b,w;
cin>>n;
for(i=1;i<=n;i++){
cin>>a[i];
}
for(i=1;i<=n;i++){
b=0;w=0;
for(j=1;j<=n;j++){
if(j<i&&a[j]>a[i])w++;
if(j>i&&a[j]<a[i])b++;
}
cout<<b+1<<" "<<n-w<<endl;
}
}