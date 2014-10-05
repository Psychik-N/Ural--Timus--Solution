#include <stdio.h>
#define low(t) (t&(t^(t-1)))
int s[10010]={0},n;
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
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d",&t);
      add(i,t);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
      scanf("%d%d",&a,&b);
      printf("%d\n",sum(b)-sum(a-1));
    }
}
