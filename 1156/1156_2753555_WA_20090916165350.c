#include <stdio.h>
int main(){
int n,m,i,j,k,ks=0,kl1[110],kl2[110],k1[110][110],k2[110][110],a,b,s1,s2,fs[110][110]={0},xk[110][110]={0};
int c[110][110]={0},cr[110][110]={1},z[110]={0};
scanf("%d%d",&n,&m);
for(i=0;i<m;i++){
scanf("%d%d",&a,&b);
if(a==b)continue;
c[a][b]=c[b][a]=1;
}
n*=2;
for(i=1;i<=n;i++){
s1=s2=1;
for(j=0;j<ks;j++){
for(k=0;k<kl1[j];k++)if(c[k1[j][k]][i])s1=0;
for(k=0;k<kl2[j];k++)if(c[k2[j][k]][i])s2=0;
if(s1==1&&s2==1)continue;
if(s1==0&&s2==0)goto fail;
if(s1==1){
k1[j][kl1[j]]=i;
kl1[j]++;
}else{
k2[j][kl2[j]]=i;
kl2[j]++;
}
break;
}
if(s1==1&&s2==1){
kl1[ks]=1;
kl2[ks]=0;
k1[ks][0]=i;
ks++;
}
}
for(i=0;i<ks;i++){
for(j=55;j>=0;j--){
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
if(cr[ks][n/2]==0)goto fail;
a=n/2;
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
for(i=1;i<=n;i++)if(z[i]==0)printf("%d ",i);
printf("\n");
for(i=1;i<=n;i++)if(z[i]!=0)printf("%d ",i);
return 0;
fail:
puts("IMPOSSIBLE");
}

