#include<iostream>
using namespace std;
int main(){
int c[7200][4]={0},z[7200]={0},n,i,j,k,z2=0,l,t;
cin>>n;
for(i=1;i<=n;i++){
cin>>c[i][0];
for(j=1;j<=c[i][0];j++)cin>>c[i][j];
}
for(l=1;l<=3;l++){
for(i=1;i<=n*2;i++){
k=0;
for(j=1;j<=c[i][0];j++)if(z[c[i][j]]==z[i])k++;
if(k>1){
z[i]=!z[i];
if(z[i]==1)z2++;
else z2--;
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