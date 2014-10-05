#include <stdio.h>
#pragma comment(linker,"/STACK:16000000")
int main(){
int n,k,i,j,e[7200][4],z[7200]={0},t,c1=0,c2=0;
scanf("%d",&n);
for(i=1;i<=n;i++){
scanf("%d",&k);
e[i][0]=k;
for(j=1;j<=k;j++)
scanf("%d",&e[i][j]);
}
for(t=1;t<499;t++){
for(j=1;j<=n;j++){
k=0;
for(i=1;i<=e[j][0];i++)
if(z[j]==z[e[j][i]])
k++;
if(k>1)
z[j]=!z[j];
}
}
for(i=1;i<=n;i++){
if(z[i]==0)c1++;
else c2++;
}
if(c1>c2){
printf("%d\n",c2);
k=1;
}else if(c1<c2){
printf("%d\n",c1);
k=0;
}else{
printf("%d\n",c1);
k=z[1];
}
for(i=1;i<=n;i++)
if(z[i]==k)
printf("%d ",i);
}
