#include <stdio.h>
#pragma comment(linker,"/STACK:16777216")
int main(){
    int n,p,i,j,k,x[510]={0},y[510]={0},f[510][510]={0},in,bv,t;
    scanf("%d%d",&n,&p);
    for(i=1;i<=n;i++){
      scanf("%d",&in);
      x[i]=x[i-1];
      y[i]=y[i-1];
      if(in==0)x[i]++;
      else y[i]++;
    }
    for(i=1;i<=n;i++)f[1][i]=x[i]*y[i];
    for(i=2;i<=p;i++){
      for(j=i;j<=n;j++){
        bv=2000000000;
        for(k=i-1;k<j;k++){
          t=f[i-1][k]+(x[j]-x[k])*(y[j]-y[k]);
          if(t<bv)bv=t;
        }
        f[i][j]=bv;
      }
    }
    printf("%d",f[p][n]);
}
