#include<iostream>
using namespace std;

int main(){
int x[20001][4]={0},n,i,j,t=0,ct,tc;
char c;
x[0][0]=1;
x[0][1]=0;
x[0][2]=1000000000;
x[0][3]=0;
cin>>n;
for(i=1;i<n;i++){
t++;
cin>>x[t][1]>>x[t][2]>>c;
if(c=='b')tc=0;
else tc=1;
x[t][0]=1;
x[t][3]=tc;
ct=t;
for(j=0;j<ct;j++){
if(x[j][0]==0)continue;
if(x[j][3]!=tc){
if(x[ct][1]>=x[j][2]||x[ct][2]<=x[j][1])continue;
else if(x[ct][1]<=x[j][1]&&x[ct][2]>=x[j][2])
x[j][0]=0;
else if(x[ct][1]>x[j][1]&&x[ct][2]<x[j][2]){
x[j][0]=0;
t++;
x[t][0]=1;
x[t][1]=x[j][1];
x[t][2]=x[ct][1];
t++;
x[t][0]=1;
x[t][1]=x[ct][2];
x[t][2]=x[j][2];
}
else if(x[ct][1]>x[j][1]){
x[j][0]=0;
t++;
x[t][0]=1;
x[t][1]=x[j][1];
x[t][2]=x[ct][1];
}
else {
x[j][0]=0;
t++;
x[t][0]=1;
x[t][1]=x[ct][2];
x[t][2]=x[j][2];
}
}
else{
if(x[ct][1]>x[j][2]||x[ct][2]<x[j][1])continue;
else{
x[j][0]=0;
x[ct][1]=min(x[ct][1],x[j][1]);
x[ct][2]=max(x[ct][2],x[j][2]);
}
}
}
}
int m=0,s=0,e=0;
for(i=0;i<=t;i++){
if(x[i][0]==0||x[i][3]==1)continue;
if(x[i][2]-x[i][1]>m){
m=x[i][2]-x[i][1];
s=x[i][1];
e=x[i][2];
}
}
cout<<s<<" "<<e;
}
