#include<iostream>
using namespace std;
int a[200],n;
int main(){
int i,t=0;
cin>>n;
for(i=1;i<=n;i++)cin>>a[i];
for(i=1;i<=n;i++){
if(a[i]>t+1){
cout<<t+1;
return 0;
}
t+=a[i];
}
cout<<t+1;
}