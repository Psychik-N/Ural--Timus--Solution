#include <stdio.h>
int main(){
int h[100010],o[100010],hs=0,i,n,k,t,now,d;
char s[5];
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&t);
now=hs;
while(now>0&&t<h[(now-1)/2]){
h[now]=h[(now-1)/2];
now=(now-1)/2;
}
h[now]=t;
hs++;
}
while(hs>0){
o[n-hs]=h[0];
hs--;
now=0;
while(now*2+1<hs){
if(now*2+2==hs)d=now*2+1;
else if(h[now*2+1]<h[now*2+2])d=now*2+1;
else d=now*2+2;
if(h[hs]<=h[d])break;
h[now]=h[d];
now=d;
}
h[now]=h[hs];
}
scanf("%s %d",s,&k);
for(i=0;i<k;i++){
scanf("%d",&t);
printf("%d\n",o[t-1]);
}
}
