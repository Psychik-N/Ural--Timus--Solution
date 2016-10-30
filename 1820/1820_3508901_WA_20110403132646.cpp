#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    if(n<=k){
        cout<<n*2;
    }else{
        cout<<(n*2+1)/k;
    }
    system("pause");
}