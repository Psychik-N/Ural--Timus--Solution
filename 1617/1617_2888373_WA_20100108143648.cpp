#include<iostream>
using namespace std;
int main(){
    int a[1000]={0},ans=0,n,i,t;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>t;
        a[t]++;
    }
    for(i=1;i<=n;i++)ans+=a[i]/4;
    cout<<ans;
}