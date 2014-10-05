#include<iostream>
using namespace std;
int n,w[21],minn=2000000000,sum=0;

void go(int a,int wei){
    if(a>n){
        int c;
        
        if(wei>sum/2)c=wei-(sum-wei);
        else c=sum-wei-wei;
        
        if(c<minn)minn=c;
        
        return;
    }
    go(a+1,wei);
    go(a+1,wei+w[a]);
}

int main(){
    int i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>w[i];
        sum+=w[i];
    }
    go(1,0);
    cout<<minn;
    system("pause");
}