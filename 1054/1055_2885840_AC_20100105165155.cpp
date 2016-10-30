#include<iostream>
using namespace std;
int n,a[50],now=0,on=1,i,j,t[2][3]={1,2,3,1,3,2};
int main(){
cin>>n;
for(i=1;i<=n;i++)cin>>a[i];
for(i=n;i>=1;i--){
on=!on;
if(t[on][(now)%3]==a[i])now=now*2;
else if(t[on][(now+1)%3]==a[i])now=now*2+1;
else{
cout<<-1;
return 0;
}
}
cout<<now;
}