#include <stdio.h>
int main(){
    int n,i,j,k,h,v[101][101],f[101][101]={0},l,bv=-1,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&v[i][j]);
    for(i=1;i<=n;i++){
      l=0;
      for(j=1;j<=n;j++){
        for(k=1;k<=i;k++)l+=v[k][j];
        f[i][j]=l;
      }
    }
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        for(k=i;k<=n;k++){
          for(h=j;h<=n;h++){
            t=f[k][h]-f[i-1][h]-f[k][j-1]+f[i-1][j-1];
            if(t>bv)bv=t;
          }
        }
      }
    }
    printf("%d",bv);
}
