#include <stdio.h>
int n,ks=0,kl1[110],kl2[110],k1[110][110],k2[110][110];
char c[110][110]={0},mark[110]={0},color[110]={0};
void dfs(int p,int tc){
     int i;
     color[p]=tc;
     mark[p]=1;
     if(tc==1){
       k1[ks][kl1[ks]]=p;
       kl1[ks]++;
     }else{
       k2[ks][kl2[ks]]=p;
       kl2[ks]++;
     }
     for(i=1;i<=n;i++){
       if((c[p][i]==1&&c[i][p]==1)||i==p)continue;
       if(mark[i]==1&&color[i]==tc){
         puts("No solution");
         exit(0);
       }
       if(mark[i]==0)dfs(i,3-tc);
     }
}
int main(){
    int m,i,j,k,a,b,s1,s2,fs[110][110],xk[110][110],in,bv,bi,c1=0;
    char cr[110][110]={1},z[110]={0};
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      while(1){
        scanf("%d",&in);
        if(in==0)break;
        c[i][in]=1;
      }
    }
    for(i=1;i<=n;i++)
      if(mark[i]==0){
        dfs(i,1);
        ks++;
      }
    for(i=0;i<ks;i++){
      for(j=50;j>=0;j--){
        if(cr[i][j]==0)continue;
        if(cr[i+1][j+kl1[i]]==0){
          cr[i+1][j+kl1[i]]=1;
          fs[i+1][j+kl1[i]]=j;
          xk[i+1][j+kl1[i]]=1;
        }
        if(cr[i+1][j+kl2[i]]==0){
          cr[i+1][j+kl2[i]]=1;
          fs[i+1][j+kl2[i]]=j;
          xk[i+1][j+kl2[i]]=2;
        }
      }
    }
    for(i=n/2;i>0;i--)if(cr[ks][i]==1){
      a=i;
      goto yes;
    }
    goto fail;
    yes:
    for(j=ks;j>0;j--){
      if(xk[j][a]==1){
        b=kl1[j-1];
        for(i=0;i<b;i++)z[k1[j-1][i]]=1;
      }else{
        b=kl2[j-1];
        for(i=0;i<b;i++)z[k2[j-1][i]]=1;
      }
      a=fs[j][a];
    }
    for(i=1;i<=n;i++)if(z[i]==0)c1++;
    printf("%d",c1);
    for(i=1;i<=n;i++)if(z[i]==0)printf(" %d",i);
    printf("\n%d",n-c1);
    for(i=1;i<=n;i++)if(z[i]!=0)printf(" %d",i);
    return 0;
    fail:
    puts("No solution");
}


