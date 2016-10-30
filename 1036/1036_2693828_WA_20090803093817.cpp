#include<iostream>
using namespace std;

long long n,s,note[51][1001]={0};

long long count(int tn,int ts){
    if(ts==0)return 1;
    if(ts>tn*10)return 0;
    if(tn==1)return 1;
    if(note[tn][ts]!=0)return note[tn][ts];
    long long ans=0,i;
    for(i=0;i<=min(9,ts);i++){
        ans+=count(tn-1,ts-i);
    }
    note[tn][ts]=ans;
    return ans;
}
int main(){
    cin>>n>>s;
    if(s%2==1){
        cout<<"0";
        return 0;
    }
    long long ans=count(n,s/2);
    cout<<ans*ans;
    system("pause");
}
