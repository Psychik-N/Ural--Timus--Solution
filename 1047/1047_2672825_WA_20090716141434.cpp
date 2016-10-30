#include<iostream>
using namespace std;
int n;
float a[4000],c[4000],a0,an1;

int main(){
cin>>n>>a0>>an1;
int i;
for(i=1;i<=n;i++)cin>>c[i];
a[0]=a0;
int s=-200000,e=200000,a1=0;
while(1){
a[1]=a1/100;
for(i=2;i<=n+1;i++)a[i]=2*a[i-1]+2*c[i-1]-a[i-2];
if(an1>a[n+1]){
s=a1;
a1=(s+e)/2;
}else if(an1>a[n+1]){
e=a1;
a1=(s+e)/2;
}else{
break;
}
}
cout<<int(a[1])<<"."<<int(a[1]*10)%10<<int(a[1]*100)%10;
}
