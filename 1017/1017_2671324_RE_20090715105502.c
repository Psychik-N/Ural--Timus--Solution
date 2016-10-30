#include <stdio.h>
long long min(long long a,long long b){
if(a<b)return a;
return b;
}
int main(){
long long f[510][510]={0},i,j,k,n;
f[0][0]=f[1][1]=f[3][2]=f[4][3]=0;
f[3][3]=f[4][4]=2;
scanf("%l64d",&n);
for(i=5;i<=n;i++)
for(j=i;j>0;j--)
for(k=j;k>=0;k--)
f[i][j]+=f[i-k][k-1];
printf("%l64d",f[n][n]);
}
