#include<iostream>
using namespace std;
char m[1010][1010];
int n;
int main(){
    int i,j,ct[4]={0},f;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>m[i][j];
            m[i][j]-=48;
        }
    }
    for(i=1;i<=n;i++){
        f=0;
        for(j=1;j<=n;j++){
            if(m[i][j]==1)f=1;
            if(f==1&&m[i][j]==0)ct[0]=1;
        }
    }
    for(i=1;i<=n;i++){
        f=0;
        for(j=n;j>=1;j--){
            if(m[i][j]==1)f=1;
            if(f==1&&m[i][j]==0)ct[1]=1;
        }
    }

    for(i=1;i<=n;i++){
        f=0;
        for(j=1;j<=n;j++){
            if(m[j][i]==1)f=1;
            if(f==1&&m[j][i]==0)ct[2]=1;
        }
    }
    for(i=1;i<=n;i++){
        f=0;
        for(j=n;j>=1;j--){
            if(m[j][i]==1)f=1;
            if(f==1&&m[j][i]==0)ct[3]=1;
        }
    }
    if(ct[0]+ct[1]+ct[2]+ct[3]==4)cout<<"No";
    else cout<<"Yes";
    system("pause");
}
