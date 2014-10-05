#include<iostream>
using namespace std;
int f=0;
char c[30001];
int main(){
cin.get(c,100000,EOF);
int l=strlen(c),i,p=0;
for(i=0;i<l;i++){
if(c[i]==13||c[i]==10||c[i]==EOF)continue;
c[p]=c[i];
p++;
}
c[p]=0;
l=strlen(c);
for(i=2;i<=l;i++)f=(f+1999)%i;
if(c[f]=='?')cout<<"Yes";
else if(c[f]==' ')cout<<"No";
else cout<<"No comments";
}