﻿include<iostream>
using namespace std;
int main(){
int n,k,i;
cin>>n>>k;
i=2*(n%k)-k;
if(i<0) i=0;
if(n<k) cout<<0;
else cout<<(n/k)*(n+n%k)+i;
}