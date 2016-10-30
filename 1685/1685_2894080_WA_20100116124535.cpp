#include<iostream>
using namespace std;
char c[100000]={0},tc[100000]={0},cop[100000]={0};
int u=0;
void go(int s,int e){
if(s>e)return;
cop[(s+e)/2]=tc[u];
u++;
go(s,(s+e)/2-1);
go((s+e)/2+1,e);
}
int main(){
cin.get(c,1000000,EOF);
int i,p=0,l=strlen(c);
for(i=0;i<l;i++){
if(c[i]==13||c[i]==10||c[i]==32||c[i]==EOF)continue;
tc[p]=c[i];
p++;
}
tc[p]=0;
l=strlen(tc);
go(0,l-1);
p=0;
for(i=0;i<l;i++){
while(c[p]!=EOF&&c[p]!=cop[i]){
cout<<c[p];
p++;
}
cout<<cop[i];
p++;
}
}