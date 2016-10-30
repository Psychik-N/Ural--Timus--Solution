#include <stdio.h>
int v[6010],n,fc[6010]={0},nb[6010]={0},hf[6010]={0};
int z(int a){
if(a>0)return a;
return 0;
}
int max(int a,int b){
if(a>b)return a;
return b;
}
int bv(int a){
int av=0,w=fc[a];
while(w!=0){
av+=bv(w);
w=nb[w];
}
return z(max(av,v[a]));
}
int main(){
int i,f,s,o=0;
scanf("%d",&n);
for(i=1;i<=n;i++)scanf("%d",&v[i]);
while(1){
scanf("%d%d",&f,&s);
if(s==0&&f==0)break;
hf[s]=1;
nb[s]=fc[f];
fc[f]=s;
}
for(i=1;i<=n;i++)if(hf[i]==0)o+=z(bv(i));
printf("%d",o);
}
