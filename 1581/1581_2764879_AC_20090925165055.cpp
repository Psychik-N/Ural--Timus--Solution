#include<iostream>
using namespace std;

int main(){
    int n,i,c=1,a,t;
    cin>>n;
    cin>>a;
    for(i=2;i<=n;i++){
        cin>>t;
        if(t==a){
            c++;
        }else{
            cout<<c<<" "<<a<<" ";
            a=t;
            c=1;
        }
    }
    cout<<c<<" "<<a<<" ";
    system("pause");
}