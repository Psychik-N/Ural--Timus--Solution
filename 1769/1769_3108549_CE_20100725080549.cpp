#include<iostream>
#include<string.h>
using namespace std;
char c[150000]={0};
int a[1000000]={0};
int main(){
int i,j,l,t;
for(i=0;i<120000;i++)c[i]=48;
cin>>c+6;
l=strlen(c);
for(i=6;i<l;i++){
t=0;
for(j=0;j<6;j++){
t=t+(c[i-j]-48)*int(pow(10,j)+0.1);
a[t]=1;
}
}
for(i=1;i<=1000000;i++){
if(a[i]==0){
cout<<i;
return 0;
}
}
while(1);
}