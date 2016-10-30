#include <stdio.h>
int min(int a,int b){
if(a<b)return a;
return b;
}
int main(){
long long f[501][501]={0};
int i,j,k,n;
f[0][0]=f[1][1]=f[2][2]=f[3][2]=f[4][3]=1;
f[3][3]=f[4][4]=2;
scanf("%d",&n);
for(i=5;i<=n;i++)
for(j=i;j>0;j--)
for(k=j;k>=0;k--)
f[i][j]+=f[i-k][min(i-k,k-1)];
printf("%lld",f[n][n]-1);
}
