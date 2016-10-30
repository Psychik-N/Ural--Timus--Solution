#include<iostream>
using namespace std;
int main(){
int i=1;
double p,q,s,x;
cin>>p>>q;
while(1){
i++;
x=i*p*100;
s=i*q*100;
if(int(x/10000)+1<=int(s/10000)&&s%10000!=0){
cout<<i;
return 0;
}
}
}