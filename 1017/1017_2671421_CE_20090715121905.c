﻿#include <stdio.h>
#include <malloc.h>
int min(int a,int b){
if(a<b)return a;
return b;
}
int main(){
long long *f[501];
for(i=0;i<501;i++)
f[i]=(long long *)malloc(sizeof(long long)*501);
for(i=0;i<501;i++)
for(j=0;j<501;j++)
f[i][j]=0;
int i,j,k,n;
f[0][0]=f[1][1]=f[2][2]=f[3][2]=f[4][3]=1;
f[3][3]=f[4][4]=2;
scanf("%d",&n);
for(i=5;i<=n;i++)
for(j=i;j>0;j--)
for(k=j;k>=0;k--)
f[i][j]+=f[i-k][min(k-1,i-k)];
printf("%lld",f[n][n]-1);
}
