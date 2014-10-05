#include<iostream>
using namespace std;
int main(){
int l,n,t,i;
cin>>l>>n;
for(i=1;i<=n;i++){
cin>>t;
l-=(l%t);
if(l<=0){cout<<"YES";return 0;}
}
cout<<"NO";
}