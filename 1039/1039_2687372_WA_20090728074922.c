#include <stdio.h>
struct P{
char r;
int v;
int fc;
int nb;
}p[6010];
int max(int a,int b){
if(a>b)return a;
return b;
}
int z(int a){
if(a>0)return a;
return 0;
}
int f(int n){
int av=0,t;
int w=p[n].fc;
while(w!=0){
av+=z(f(w));
w=p[w].nb;
}
t=max(p[n].v,av);
return t;
}
int main(){
int n,i,l,k,s=0,t;
scanf("%d",&n);
for(i=1;i<=n;i++){
p[i].r=1;
scanf("%d",&(p[i].v));
p[i].fc=p[i].nb=0;
}
while(1){
scanf("%d %d",&l,&k);
if(l==0&&k==0)break;
p[l].r=0;
p[l].nb=p[k].fc;
p[k].fc=l;
}
for(i=1;i<=n;i++)
if(p[i].r){
s+=f(i);
}
printf("%d",s);
}
