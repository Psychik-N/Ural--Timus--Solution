#include <stdio.h>
struct Edge{
       int num;
       struct Edge *next;
}edg[101],*tail[101],*t;
int ms(){
    int s;
    char c;
    do{
         c=getchar();
    }while(c<48||c>57);
    s=c-48;
    while(1){
      c=getchar();
      if(c<48||c>57)return s;
      s=s*10+c-48;
    }
}
void mp(int s){
     char b[10];
     int l=0,i;
     while(s){
       b[l]=s%10+48;
       l++;
       s/=10;
     }
     for(i=l-1;i>=0;i--)putchar(b[i]);
}
int main(){
    int n,i,a,b;
    n=ms();
    for(i=0;i<=100;i++){
      edg[i].next=0;
      tail[i]=&edg[i];
    }
    for(i=0;i<n;i++){
      a=ms();
      b=ms();
      t=new Edge;
      t->num=a;
      tail[b]->next=t;
      tail[b]=t;
    }
    for(i=0;i<=100;i++)tail[i]->next=0;
    for(i=100;i>=0;i--){
      t=edg[i].next;
      while(t){
        mp(t->num);
        putchar(' ');
        mp(i);
        putchar('\n');
        t=t->next;
      }
    }
}
