#include<iostream>
using namespace std;

int main(){
    int g[210][210][4]={0},m,n,i,j,k,d,ans=0,t;
    char c;
    cin>>m>>n;
    for(k=0;k<=2;k++){
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                cin>>c;
                if(c=='/'){
                    if(i%2==0&&j%2==0)t=1;
                    else if(i%2==1&&j%2==0)t=2;
                    else if(i%2==0&&j%2==1)t=2;
                    else t=1;
                    g[j][i-1][t^k]++;
                    g[j-1][i][t^k]++;
                }else if(c=='\\'){
                    if(i%2==0&&j%2==0)t=0;
                    else if(i%2==1a&&j%2==0)t=3;
                    else if(i%2==0&&j%2==1)t=3;
                    else t=2;
                    g[j-1][i-1][(i%2+j%2+k+1)%2]++;
                    g[j][i][(i%2+j%2+k+1)%2]++;
                }else if(c=='X'){
                    g[j][i-1][(i%2+j%2+k)%2]++;
                    g[j-1][i][(i%2+j%2+k)%2]++;
                    g[j-1][i-1][(i%2+j%2+k+1)%2]++;
                    g[j][i][(i%2+j%2+k+1)%2]++;
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