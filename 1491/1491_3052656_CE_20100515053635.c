#include <stdio.h>
int ps[300000],pe[300000],pc[300000]={0};
int max(int a,int b){
if(a>b)return a;
return b;
}
int min(int a,int b){
if(a<b)return a;
return b;
}
void init(int p,int s,int e){
int m=(s+e)/2;
ps[p]=s;
pe[p]=e;
if(s==e)return;
init(p*2+1,s,m);
init(p*2+2,m+1,e);
}
void add(int p,int s,int e,int v){
if(ps[p]==s&&pe[p]==e){
pc[p]+=v;
return;
}
if(s<=pe[p*2+1])add(p*2+1,s,min(e,pe[p*2+1],v);
if(e>=ps[p*2+2])add(p*2+2,max(s,ps[p*2+2]),e,v);
}
int get(int p,int a){
if(a<ps[p*2+2])return get(p*1+2,a)+pc[p];
else return get(p*2+1,a)+pc[p];
}
int main(){
int n,i,a,b,c,s=0;
init(0,0,110000);
scanf("%d",&n);
for(i=0;i<=n;i++){
scanf("%d%d%d",&a,&b,&c);
add(0,a,b,c);
}
for(i=1;i<=n;i++)printf("%d\n",get(0,i));
}
