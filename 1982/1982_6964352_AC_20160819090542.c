#include <stdio.h>
int c[101][101];
int m[101]={0};
int main(){
    int n,k,ans=0,i,j,bv=0,bj=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<k;i++){
        scanf("%d",&j);
        m[j]=1;
    }
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&c[i][j]);
    for(i=k;i<n;i++){
        bv=2000000000;
        for(j=1;j<=n;j++)if(m[j]==0)for(k=1;k<=n;k++)if(m[k]==1&&c[j][k]<bv){
            bv=c[j][k];
            bj=j;
        }
        m[bj]=1;
        ans+=bv;
    }
    printf("%d\n",ans);
    return 0;
}
