#include <stdio.h>
#pragma comment(linker,"/STACK:16000000")
int main(){
int s[7200],sl=0,n,k,i,j,count[7200],e[7200][4],z[7200]={0},t,c1=0,c2=0;
scanf("%d",&n);
for(i=1;i<=n;i++){
scanf("%d",&k);
e[i][0]=count[i]=k;
for(j=1;j<=k;j++)
scanf("%d",&e[i][j]);
if(k>1){
s[sl]=1;
sl++;
}
}
while(sl>0){
sl--;
t=s[sl];
z[t]=!z[t];
for(i=1;i<=e[t][0];i++){
k=e[t][i];
if(z[t]==z[k])
count[k]++;
else
count[k]--;
if(count[k]>1){
s[sl]=k;
sl++;
}
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
