#include <stdio.h>
int m[110][110],n,i,j;
int main(){
scanf("%d",&n);
for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&m[i][j]);
for(i=0;i<n+n-1;i++)for(j=0;j<n;j++){
if(i-j<0||i-j>=n)continue;
printf("%d ",m[i-j][j]);
}
}
