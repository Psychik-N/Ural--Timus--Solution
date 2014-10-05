#include <stdio.h>
struct I{int x,y,id;}p[10010],*h[10010];
int hs=0;
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
void mp(int s){
     char b[12];
     int l=0,i,m=0;
     if(s==0){
       putchar(48);
       return;
     }
     if(s<0){
       m=1;
       s=-s;
     }
     while(s){
       b[l]=s%10;
       l++;
       s/=10;
     }
     if(m)putchar('-');
     for(i=l-1;i>=0;i--)putchar(b[i]+'0');
}
void add(struct I *i){
     int now=hs;
     while(now>0){
       if(h[(now-1)/2]->x<i->x)break;
       h[now]=h[(now-1)/2];
       now=(now-1)/2;
     }
     h[now]=i;
     hs++;
}
struct I *get(){
       struct I *r=h[0];
       int now=0,dest;
       hs--;
       while(now*2+1<hs){
         if(now*2+2==hs)dest=now*2+1;
         else if(h[now*2+1]->x<h[now*2+2]->x)dest=now*2+1;
         else dest=now*2+2;
         if(h[hs]->x<=h[dest]->x)break;
         h[now]=h[dest];
         now=dest;
       }
       h[now]=h[hs];
       return r;
}
int main(){
    int n,i;
    n=ms();
    for(i=1;i<=n;i++){
      p[i].x=ms();
      p[i].y=ms();
      p[i].id=i;
      add(&p[i]);
    }
    while(hs>0){
      mp(get()->id);
      putchar(' ');
      mp(get()->id);
      putchar('\n');
    }
}
