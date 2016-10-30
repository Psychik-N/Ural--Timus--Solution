#include<iostream>
using namespace std;

int main(){
    int g[210][210][2]={0},m,n,i,j,k,d,ans=0;
    char c;
    cin>>m>>n;
    for(k=0;k<=1;k++){
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                cin>>c;
                if(c=='/'){
                    g[j][i-1][(i+j+k)%2]++;
                    g[j-1][i][(i+j+k)%2]++;
                }else if(c=='\\'){
                    g[j-1][i-1][(i+j+k+1)%2]++;
                    g[j][i][(i+j+k+1)%2]++;
                }else if(c=='X'){
                    g[j][i-1][(i+j+k)%2]++;
                    g[j-1][i][(i+j+k)%2]++;
                    g[j-1][i-1][(i+j+k+1)%2]++;
                    g[j][i][(i+j+k+1)%2]++;
                }else;
            }
        }
        d=0;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(g[j][i][k]%2==1)d++;
            }
        }
        if(d==0)ans++;
        else ans+=(d/2);
    }
    cout<<ans;
    system("pause");
}