#include<iostream>
using namespace std;
int main(){
    long long n,p,sum[10000],i,j=0;
    cin>>n>>p; 
    while(n!=0&&p!=0){
        sum[j]=1;
        for(i=2;i<=n;i++)sum[j]=(sum[j]*i%p)%p;
        cin>>n>>p;
        j++;
    }
    for(i=0;i<j;i++)
    cout<<sum[i]<<endl;
    system("pause");
}
