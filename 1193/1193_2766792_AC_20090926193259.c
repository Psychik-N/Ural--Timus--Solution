#include <stdio.h>
struct P{int a,b,c,m;}ys[110],*p[110];
int z(int a){
    if(a>0)return a;
    return 0;
}
int max(int a,int b){
    if(a>b)return a;
    return b;
}
int main(){
    int n,i,j,mi,mv,bv=0,lst=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){scanf("%d%d%d",&(ys[i].a),&(ys[i].b),&(ys[i].c));ys[i].m=0;}
    for(i=0;i<n;i++){
      mv=20000;
      for(j=0;j<n;j++)if(ys[j].a<mv&&ys[j].m==0){
        mv=ys[j].a;
        mi=j;
      }
      p[i]=&ys[mi];
      ys[mi].m=1;
    }
    for(i=0;i<n;i++){
      lst=max(lst,p[i]->a)+p[i]->b;
      bv=max(bv,z(lst-(p[i]->c)));
    }
    printf("%d",bv);
}
