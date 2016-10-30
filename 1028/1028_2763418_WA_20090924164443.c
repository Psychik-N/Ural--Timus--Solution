#include <stdio.h>
int pc[66000]={0},ps[66000],pe[66000],l[33000]={0};
int min(int a,int b){
if(a<b)return a;
return b;
}
int max(int a,int b){
if(a>b)return a;
return b;
}
void init(int p,int s,int e){
int mid=(s+e)/2;
ps[p]=s;
pe[p]=e;
if(s==e)return;
init(p*2+1,s,mid);
init(p*2+2,mid+1,e);
}
int query(int p,int n){
if(ps[p]==pe[p])return pc[p];
if(n<=pe[p*2+1])return pc[p]+query(p*2+1,n);
return pc[p]+query(p*2+2,n);
}
void add(int p,int s,int e){
if(s==ps[p]&&e==pe[p]){
pc[p]++;
return;
}
if(s<=pe[p*2+1])add(p*2+1,s,min(e,pe[p*2+1]));
if(e>=ps[p*2+2])add(p*2+2,max(ps[p*2+2],s),e);
}
int main(){
int n,i,x,y;
init(0,0,32000);
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d%d",&x,&y);
l[query(0,x)]++;
add(0,0,x);
}
for(i=0;i<n;i++)printf("%d\n",l[i]);
}
