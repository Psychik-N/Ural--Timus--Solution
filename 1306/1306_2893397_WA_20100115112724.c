﻿#include <stdio.h>
int h[200000],s=0;
int ms(){
    int s=0;
    char c,m=0;
    do{
      c=getchar();
    }while((c!='-')&&(c<48||c>57));
    if(c=='-')m=1;
    else s=c-48;
    while(1){
      c=getchar();
      if(c<48||c>57)break;
      s=s*10+c-48;
    }
    if(m)return -s;
    return s;
}
void add(int v){
int now=s;
while(now>0){
if(v>=h[(now-1)>>1])break;
h[now]=h[(now-1)>>1];
now=(now-1)>>1;
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
int n,i,thrown=0,t,x=n/2;
n=ms();
for(i=0;i<n;i++){
t=ms();
add(t);
if(s>199771){
get();
thrown++;
}
}
if(n&1){
for(i=thrown;i<=x;i++)t=get();
printf("%.1lf",(double)t);
}else{
for(i=thrown;i<x;i++)t=get();
printf("%.1lf",((double)t+get())/2);
}
}

