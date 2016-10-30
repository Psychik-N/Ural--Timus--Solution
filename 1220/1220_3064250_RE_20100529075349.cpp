#include<iostream>
using namespace std;
int e[200000][2]={0},t=3000;
char c[10];
int main(){
int n,i,a,b;
cin>>n;
for(i=1;i<=n;i++){
cin>>c[1]>>c[1];
if(c[1]=='U'){
cin>>a>>b;
e[t][0]=b;
e[t][1]=e[a][1];
e[a][1]=t;
t++;
}else{
cin>>a;
cout<<e[e[a][1]][0];
e[a][1]=e[e[a][1]][1];
}
}
}