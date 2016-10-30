#include<iostream>
using namespace std;
int main(){
int i=1;
float p,q,s,x;
cin>>p>>q;
while(1){
i++;
x=i*p/100;
s=i*q/100;
if(int(x)+1<s){
cout<<i;
return 0;
}
}
}