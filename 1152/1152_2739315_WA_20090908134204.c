#include <stdio.h>
#pragma comment(linker,"/STACK:16777216")
int f[1100000],n,r[25];
int go(int stat,int sum){
int i,t,bv=2000000000,k;
for(i=0;i<n;i++){
k=sum;
t=stat;
if(stat&(1<<i)){
t=t^(1<<i);
k-=r[i];
}
if(i>0){
if(stat&(1<<(i-1))){
t=t^(1<<(i-1));
k-=r[i-1];
}
}else{
if(stat&(1<<(n-1))){
t=t^(1<<(n-1));
k-=r[n-1];
}
}
if(i>1){
if(stat&(1<<(i-2))){
t=t^(1<<(i-2));
k-=r[i-2];
}
}else{
if(stat&(1<<(n-2))){
t=t^(1<<(n-2));
k-=r[n-2];
}
}
if(t==stat)continue;
if(f[t]!=-1)k+=f[t];
else k+=go(t,k);
if(k<bv)bv=k;
}
f[stat]=bv;
return bv;
}
int main(){
int i,s=0;
scanf("%d",&n);
for(i=n-1;i>=0;i--){
scanf("%d",&r[i]);
s+=r[i];
}
for(i=1;i<1100000;i++)f[i]=-1;
f[0]=0;
printf("%d",go((1<<n)-1,s));
}
