#include<iostream>
using namespace std;
int b[501][501]={0};
int min(int a, int cc int c){
if(cc<a)a=cc;
if(c<a)a=c;
return a;
}

int f(int i,int j){
if(j<=0)return 0;
if(b[i][j]!=0)return b[i][j];
int s=0,k;
for(k=1;k<i;k++)s+=f(k,min(j-1,i-k-1,k));
if(i<=j)s++;
b[i][j]=s;
return s;
}

int main(){
int n;
cin>>n;
cout<<f(n,n)-1;
return 0;
