#include <stdio.h>
int m[110][110],p=0,n,i,j,o[11000],ol=0;
int main(){
scanf("%d",&n);
for(i=0;i<n;i++)for(j=0;j<n;j++)m[i][j]=++p;
for(i=0;i<n+n-1;i++)for(j=0;j<n;j++){
if(i-j<0||i-j>=n)continue;
o[ol++]=m[i-j][j];
}
for(i=1;i<=n;i++){
for(j=1;j<=n;j++)printf("%d ",o[i*n-j]);
printf("\n");
}
}
