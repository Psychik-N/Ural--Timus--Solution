#include<iostream>
using namespace std;
int m,n
int main(){
cin>>m>>n;
if(m==1||n==1)cout<<(m+n)/2;
else if((m*n)%3==0)cout<<2;
else cout<<1;
}