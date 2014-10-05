#include<iostream>
using namespace std;

int main(){
    int b,r,y,ans=1,n,i;
    char c[100];
    cin>>b>>r>>y>>n;
    for(i=1;i<=n;i++){
        cin>>c;
        if(c[0]=='R')ans*=r;
        else if(c[0]=='B')ans*=b;
        else ans*=y;
    }
    cout<<ans;
    system("pause");
}