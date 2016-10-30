#include <stdio.h>
long long f[2][301]={0},g[2][301]={0};
const int m=1000000007;
int main(){
    int n,i,j,a,b,on=0;
    long long ans=0;
    f[1][1]=g[1][1]=1;
    scanf("%d%d%d",&n,&a,&b);
    for(i=2;i<=n;i++){
        for(j=2;j<=a;j++)f[on][j]=f[!on][j-1];
        for(j=2;j<=b;j++)g[on][j]=g[!on][j-1];
        f[on][1]=g[on][1]=0;
        for(j=1;j<=a;j++)g[on][1]+=f[!on][j];
        for(j=1;j<=b;j++)f[on][1]+=g[!on][j];
        f[on][1]%=m;
        g[on][1]%=m;
        on=!on;
    }
    for(j=1;j<=a;j++)ans+=f[!on][j];
    for(j=1;j<=b;j++)ans+=g[!on][j];
    printf("%lld\n",ans%m);
    return 0;
}
