#include<iostream>
using namespace std;

int main(){
    int n[100000]={0},i,na,nb,t;
    cin>>na;
    for(i=1;i<=na;i++){
        cin>>t;
        n[t+50000]=1;
    }
    cin>>nb;
    for(i=1;i<=nb;i++){
        cin>>t;
        if(n[10000-t+50000]==1){
            cout<<"YES";
            system("pause");
            return 0;
        }
    }
    cout<<"NO";
    system("pause");
    return 0;
}