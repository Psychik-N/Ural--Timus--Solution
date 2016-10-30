#include <stdio.h>
#pragma comment(linker,"/STACK:16777216")
int main(){
int m,n,i,j,k,v[101][501],from[101][501]={0},o[100000],ol;
long long f[101][501],t[501],s;
scanf("%d %d",&m,&n);
for(i=1;i<=m;i++)for(j=1;j<=n;j++)scanf("%d",&v[i][j]);
for(i=1;i<=n;i++)f[1][i]=t[i]=v[1][i];
for(i=1;i<m;i++){
for(k=1;k<=n;k++){
s=t[k];
for(j=k-1;j>0;j--){
s+=v[i][j];
if(s<f[i][j]){f[i][j]=s;from[i][j]=k;}
}
s=t[k];
for(j=k+1;j<=n;j++){
s+=v[i][j];
if(s<f[i][j]){f[i][j]=s;from[i][j]=k;}
}
}
for(j=1;j<=n;j++){
f[i+1][j]=t[j]=f[i][j]+v[i+1][j];
from[i+1][j]=j;
}
}
k=2000000000;
for(i=1;i<=n;i++)if(f[m][i]<k){k=f[m][i];j=i;}
k=m;
while(from[k][j]!=0){
if(from[k][j]<j)for(i=j;i>=from[k][j];i--){o[ol]=i;ol++;}
else for(i=j;i<=from[k][j];i++){o[ol]=i;ol++;}
j=from[k][j];
k--;
}
printf("%d",j);
for(i=ol-1;i>=0;i--)printf(" %d",o[i]);
}
