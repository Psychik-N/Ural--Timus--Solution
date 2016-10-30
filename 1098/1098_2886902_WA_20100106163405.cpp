#include<iostream>
using namespace std;
int f[50000]={0};
char c[50000];
int main(){
cin.get(c,100000,EOF);
int l=strlen(c),i,p=0;
for(i=0;i<l;i++){
if(c[i]==13||c[i]==10||c[i]==255||c[i]==EOF)continue;
c[p]=c[i];
p++;
}
c[p]=0;
l=strlen(c)-1;
for(i=2;i<=l;i++)f[i]=(f[i-1]+1999)%i;
if(c[f[l]]=='?')cout<<"Yes";
else if(c[f[l]]==' ')cout<<"No";
else cout<<"No comments";
}