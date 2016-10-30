#include<iostream>
using namespace std;
int main(){
int c[7200][4]={0},z[7200]={0},n,i,j,k,z2=0,l,t;
cin>>n;
for(i=1;i<=n;i++){
cin>>c[i][0];
for(j=1;j<=c[i][0];j++)cin>>c[i][j];
}
for(l=1;l<=n;l++){
for(t=0;t<=1;t++){
for(i=1;i<=n*2;i++){
k=0;
for(j=1;j<=c[i][0];j++)if(z[c[i][j]]==t&&z[i]==t)k++;
if(k>1){
z[i]=!t;
if(t==0)z2++;
else z2--;
}
}
}
}
if(z2<n-z2){
cout<<z2<<endl;
k=1;
}else if(z2>n-z2){
cout<<n-z2<<endl;
k=0;
}else{
cout<<z2<<endl;
k=z[1];
}
for(i=1;i<=n;i++)if(z[i]==k)cout<<i<<" ";
}