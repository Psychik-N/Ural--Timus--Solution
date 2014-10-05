#include<iostream>
using namespace std;
//ifstream cin("1019.in");
//ofstream cout("1019.out");

int main(){
int x[20004][4]={0},n,i,j,t=0,ct,tc,a,b,m=0,s=0,e=0,mx=1000000000,tt[20004][3]={0},ttl=0;
char c;
x[0][0]=1;
x[0][1]=0;
x[0][2]=1000000000;
x[0][3]=0;
cin>>n;
for(i=1;i<=n;i++){
 cin>>a>>b>>c;
 if(a==b){
  continue;
 }
 t++;
 x[t][1]=a;
 x[t][2]=b;
 if(c=='w'){
  tc=0;
 }
 else{ 
  tc=1;
 }
 x[t][0]=1;
 x[t][3]=tc;
 ct=t;
 for(j=0;j<ct;j++){
  if(x[j][0]==0){
   continue;
  }
  if(x[j][3]!=tc){
   if(x[ct][1]>=x[j][2]||x[ct][2]<=x[j][1]){
    continue;
   }
   else if(x[ct][1]<=x[j][1]&&x[ct][2]>=x[j][2]){
    x[j][0]=0;
   }
   else if(x[ct][1]>x[j][1]&&x[ct][2]<x[j][2]){
    x[j][0]=0;
    t++;
    x[t][0]=1;
    x[t][1]=x[j][1];
    x[t][2]=x[ct][1];
    x[t][3]=x[j][3];
    t++;
    x[t][0]=1;
    x[t][1]=x[ct][2];
    x[t][2]=x[j][2];
    x[t][3]=x[j][3];
   }
   else if(x[ct][1]>x[j][1]){
    x[j][0]=0;
    t++;
    x[t][0]=1;
    x[t][1]=x[j][1];
    x[t][2]=x[ct][1];
    x[t][3]=x[j][3];
   }
   else if(x[ct][2]<x[j][2]){
    x[j][0]=0;
    t++;
    x[t][0]=1;
    x[t][1]=x[ct][2];
    x[t][2]=x[j][2];
    x[t][3]=x[j][3];
   }
   else{
   }
  }
  else{
   if(x[ct][1]>x[j][2]||x[ct][2]<x[j][1]){
    continue;
   }
   else{
    x[j][0]=0;
    x[ct][1]=min(x[ct][1],x[j][1]);
    x[ct][2]=max(x[ct][2],x[j][2]);
    x[ct][3]=x[j][3];
   }
  }
 }
}

for(i=0;i<=t;i++){
 if(x[i][0]==0||x[i][3]==1){
  continue;
 }
 if(x[i][2]-x[i][1]>m){
  ttl=0;
  m=x[i][2]-x[i][1];
  tt[ttl][1]=x[i][1];
  tt[ttl][2]=x[i][2];
  tt[ttl][0]=x[i][0];
 }
 else if(x[i][2]-x[i][1]==m){
  ttl++;
  tt[ttl][1]=x[i][1];
  tt[ttl][2]=x[i][2];
  tt[ttl][0]=x[i][0];
 }
 else{
 }
}
for(i=0;i<=ttl;i++){
if(tt[i][1]<mx){
mx=tt[i][1];
s=tt[i][1];
e=tt[i][2];
}
}
cout<<s<<" "<<e;
}
