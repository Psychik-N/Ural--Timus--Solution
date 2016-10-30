#include <stdio.h>
const int mod=1000000009;
int f[10001][10][10]={0};
int p[1000]={0};
int main(){
    int i,j,n,ans=0;
    for(i=100;i<1000;i++){
        for(j=2;j<i;j++)if(i%j==0)goto nxt;
        p[i]=1;
    nxt:;
    }
    for(i=100;i<1000;i++)if(p[i]==1)f[3][(i/10)%10][i%10]++;
    for(i=4;i<10001;i++)for(j=100;j<1000;j++)if(p[j]==1)f[i][(j/10)%10][j%10]=(f[i][(j/10)%10][j%10]+f[i-1][j/100][(j/10)%10])%mod;
    scanf("%d",&n);
    for(i=0;i<10;i++)for(j=0;j<10;j++)ans=(ans+f[n][i][j])%mod;
    printf("%d\n",ans);
    return 0;
}
