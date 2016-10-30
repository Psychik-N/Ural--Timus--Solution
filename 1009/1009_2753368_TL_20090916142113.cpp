#include<iostream>
using namespace std;

int sum=0,n,k,a[17]={0};
void go(int step){
    int i;
    if(step>n){
        sum++;
        return;
    }
    for(i=0;i<k;i++){
        if(i==0&&a[step-1]==0){
            continue;
        }
        a[step]=i;
        go(step+1);
    }
}


int main(){
    
    cin>>n>>k;
    go(1);
    cout<<sum;
    system("pause");
}