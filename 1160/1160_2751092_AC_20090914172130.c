#include <stdio.h>
#include <stdlib.h>
struct Edge{
int to,len;
struct Edge *next;
}*edg[1010]={0},*t;
int ms(){
int s;
char c;
do{
c=getchar();
}while(c<'0'||c>'9');
s=c-'0';
while(1){
c=getchar();
if(c<'0'||c>'9')break;
s=s*10+c-'0';
}
return s;
}
void mp(int s){
char b[15];
int l=0,i;
while(s){
b[l]=s%10+'0';
l++;
s/=10;
}
for(i=l-1;i>=0;i--)putchar(b[i]);
}
int main(){
    int n,m,i,j,mi,mv,bv=-1,a,b,l,cls[1010],lc[1010],c1[1010],c2[1010];
    n=ms();
    m=ms();
    for(i=0;i<m;i++){
      a=ms();
      b=ms();
      l=ms();
      t=malloc(12);
      t->to=b;
      t->len=l;
      t->next=edg[a];
      edg[a]=t;
      t=malloc(12);
      t->to=a;
      t->len=l;
      t->next=edg[b];
      edg[b]=t;
    }
    lc[1]=2000000000;
    for(i=2;i<=n;i++){
      lc[i]=1000000000;
      cls[i]=1;
    }
    t=edg[1];
    while(t){
      lc[t->to]=t->len;
      t=t->next;
    }
    for(i=2;i<=n;i++){
      mv=2000000000;
      for(j=2;j<=n;j++){
        if(lc[j]<mv){
          mv=lc[j];
          mi=j;
        }
      }
      c1[i]=mi;
      c2[i]=cls[mi];
      if(mv>bv)bv=mv;
      lc[mi]=2000000000;
      t=edg[mi];
      while(t){
        if(lc[t->to]<2000000000&&t->len<lc[t->to]){
          lc[t->to]=t->len;
          cls[t->to]=mi;
        }
        t=t->next;
      }
    }
    mp(bv);
    putchar('\n');
    mp(n-1);
    putchar('\n');
    for(i=2;i<=n;i++){
      mp(c1[i]);
      putchar(' ');
      mp(c2[i]);
      putchar('\n');
    }
}
