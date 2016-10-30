#include <stdio.h>
int h[200000],s=0;
void add(int v){
int now=s;
while(now>0){
if(h[now]<=h[(now-1)/2])break;
h[now]=h[(now-1)/2];
now=(now-1)/2;
}
s++;
h[now]=v;
}
int get(){
int now=0,dest,r=h[0];
s--;
while(now*2+1<s){
if(now*2+2==s)dest=now*2+1;
else if(h[now*2+1]<h[now*2+2])dest=now*2+1;
else dest=now*2+2;
if(h[s]<=h[dest])break;
h[now]=h[dest];
now=dest;
}
h[now]=h[s];
return r;
}
int main(){
int n,i,thrown=0,t;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&t);
add(t);
if(s>199310){
get();
thrown++;
}
}
if(n&1){
for(i=thrown;i<=n/2;i++)t=get();
printf("%d",t);
}else{
for(i=thrown;i<n/2;i++)t=get();
printf("%.1lf",((double)t+get())/2);
}
}
