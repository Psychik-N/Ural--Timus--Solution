#include<iostream>
#include<math.h>
using namespace std;

int main(){
long long n,l[10]={0},r[10]={0},i,j,c[10]={0};
int w=0,nt;
cin>>n;
nt=n;
while(nt>0){
w++;
nt/=10;
}
for(i=1;i<=9;i++){
l[i]=n/pow(10,9-i);
r[i]=n%(int)pow(10,i);
}
for(i=0;i<=9;i++){
for(j=1;j<=w;j++){
c[i]+=l[9-j]*pow(10,j-1)+min(r[j]-(pow(10,j-1)*i-1),pow(10,j-1));
}
}
c[0]-=w;
int now=0;
i=1;
for(j=1;j<=w;j++){
c[0]-=(r[j]-now)*(w-j);
now+=(r[j]-now)*(w-j);
}
for(i=0;i<=9;i++)cout<<c[i]<<endl;
}