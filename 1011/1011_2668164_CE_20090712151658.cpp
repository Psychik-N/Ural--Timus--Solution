#include<iostream>
using namespace std;
int main(){
int i=1;
double p,q,s,x;
cin>>p>>q;
while(1){
i++;
x=i*p;
s=i*q;
if( (int)(x/100) + 1 <= (int) (s/100) &&( ( s%100 )!=0) ){
cout<<i;
return 0;
}
}
return 0;
}