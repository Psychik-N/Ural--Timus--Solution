#include<iostream>
using namespace std;
int a[40000],s,n;
int main(){
int i,t;
cin>>s>>n;
for(i=1;i<=s;i++)cin>>a[i];
t=0;
for(i=1;i<=s;i++){
t+=a[i];
if(t<i){
cout<<"NO";
return 0;
}
}
t=0;
for(i=1;i<=s;i++){
t+=a[s-i+1];
if(t<i){
cout<<"NO";
return 0;
}
}
cout<<"YES";
}