#include<iostream>
using namespace std;
int main(){
    int n,m[100][100]={0},i,j,k,ans,x,u[3000]={0};
    cin>>n;
    ans=n*n+n/2+1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            x=max(m[i-1][j],m[i][j-1]);
            x=min(x,n*n);
            for(k=x;k>=1;k--){
                if(u[k]==0){
                    m[i][j]=k;
                    u[k]=1;
                    break;
                }
            }
            cout<<k<<" ";
        }
        cout<<endl;
    }
    system("pause");
}