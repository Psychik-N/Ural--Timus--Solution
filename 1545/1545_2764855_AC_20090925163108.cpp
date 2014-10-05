#include<iostream>
using namespace std;

int main(){
    int n,i;
    char v[1001][2],b;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>v[i][0]>>v[i][1];
    }
    cin>>b;
    for(i=1;i<=n;i++){
        if(v[i][0]==b){
            cout<<v[i][0]<<v[i][1]<<endl;
        }
    }
    system("pause");
}