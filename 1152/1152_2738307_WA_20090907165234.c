#include <stdio.h>
int f[1100000],n,r[25];
int go(int stat){
int bv=2000000000,i,j,k,t;
if(f[stat]!=-1)return f[stat];
for(i=0;i<n;i++){
t=stat|(1<<i);
if(t!=stat){
k=go(t);
if(k<bv)bv=k;
}
if(i>=1)t=t|(1<<(i-1));
else t=t|(1<<(n-1));
if(t!=stat){
k=go(t);
if(k<bv)bv=k;
}
if(i>=2)t=t|(1<<(i-2));
else t=t|(1<<(n-2));
if(t!=stat){
k=go(t);
if(k<bv)bv=k;
}
}
for(i=0;i<n;i++)if(stat&(1<<i))bv+=r[n-i-1];
f[stat]=bv;
return bv;
}
int main(){
int i;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d",&r[i]);
if(n<=3){puts("0");return 0;}
for(i=0;i<1100000;i++)f[i]=-1;
f[(1<<n)-1]=0;
printf("%d",go(0));
}
