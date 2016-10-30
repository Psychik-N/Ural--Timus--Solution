#include <stdio.h>
#define low(t) (t&(t^(t-1)))
int s[10010]={0},n;
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
void add(int x,int v){
     int i;
     for(i=x;i<=n;i+=low(i))s[i]+=v;
}
int sum(int x){
    int i,v=0;
    for(i=x;i>0;i-=low(i))v+=s[i];
    return v;
}
int main(){
    int i,q,t,a,b;
    n=ms();
    for(i=1;i<=n;i++){
      t=ms();
      add(i,t);
    }
    q=ms();
    for(i=0;i<q;i++){
      a=ms();
      b=ms();
      printf("%d\n",sum(b)-sum(a-1));
    }
}
