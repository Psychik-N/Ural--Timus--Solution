#include<iostream>
using namespace std;
long long n,a,t=0,m;
int main(){
int i;
cin>>n>>m;
for(i=1;i<=m;i++){
cin>>a;
t+=a;
if(t>n*3){
cout<<"Free after "<<i<<" times.";
return 0;
}
}
cout<<"Team.GOV!";
}