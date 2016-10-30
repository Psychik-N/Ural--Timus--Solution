#include<iostream>
using namespace std;
int main(){
    int g[110][110],n,m,l,z[110],s[110],y[110],f[110],t,bi=1,bv=1000000;
    int i,j,k,a,b;
    cin>>n>>m;
    memset(g,-1,110*110*4);
    for(i=1;i<=m;i++){
        cin>>l;
        for(j=1;j<=l;j++)cin>>z[j];
        for(a=1;a<=l;a++)for(b=1;b<=l;b++)g[z[a]][z[b]]=4;
        for(a=1;a<=l;a++)g[z[a]][z[a]]=0;
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(g[i][k]==-1||g[k][j]==-1)continue;
                if(g[i][k]+g[k][j]<g[i][j]||g[i][j]==-1)g[i][j]=g[i][k]+g[k][j];
            }
        }
    }
    cin>>k;
    for(i=1;i<=k;i++)cin>>s[i]>>f[i]>>y[i];
    for(i=1;i<=n;i++){
        t=0;
        for(j=1;j<=k;j++){
            if(g[i][f[j]]==-1||s[j]<g[i][f[j]])t=1000000;
            if(y[j]==0)t+=g[i][f[j]];
        }
        if(t<bv){
            bv=t;
            bi=i;
        }
    }
    if(bv==1000000)cout<<0;
    else cout<<bi<<" "<<bv;
    system("pause");
}
    
