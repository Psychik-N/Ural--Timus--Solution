#include <stdio.h>
int h[210010],s=0;
int ms(){
    int s=0;
    char c;
    do{
      c=getchar();
    }while(c<48||c>57);
    s=c-48;
    while(1){
      c=getchar();
      if(c<48||c>57)break;
      s=s*10+c-48;
    }
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
while((now<<1)+1<s){
if((now<<1)+2==s)dest=(now<<1)+1;
else if(h[(now<<1)+1]<h[(now<<1)+2])dest=(now<<1)+1;
else dest=(now<<1)+2;
if(h[s]<=h[dest])break;
h[now]=h[dest];
now=dest;
}
h[now]=h[s];
return r;
}
int main(){
int n,i,thrown=0,t,x;
n=ms();
for(i=0;i<n;i++){
t=ms();
add(t);
if(s>210000){
get();
thrown++;
}
}
x=n/2;
if(n&1){
for(i=thrown;i<=x;i++)t=get();
printf("%.1lf",(double)t);
}else{
for(i=thrown;i<x;i++)t=get();
printf("%.1lf",((double)t+get())/2);
}
}

