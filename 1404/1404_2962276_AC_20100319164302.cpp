#include<iostream>
using namespace std;
int main(){
    int i,a[100],l,t,b[200];
    char c[200];
    cin>>c;
    l=strlen(c);
    for(i=0;i<l;i++)a[i]=c[i]-97;
    b[0]=(a[0]+21)%26;
    for(i=1;i<l;i++)b[i]=(a[i]+260-a[i-1])%26;
    for(i=0;i<l;i++)cout<<char(b[i]+97);
    system("pause");
}