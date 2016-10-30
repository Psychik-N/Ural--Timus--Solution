#include <stdio.h>
int main(){
    int d,e,f,dp,ep,h,i;
    scanf("%d%d%d%d%d%d",&d,&e,&f,&dp,&ep,&h);
    if(f==0){
      printf("YES");
      return 0;
    }
    dp--;
    ep--;
    if(d>e){
      i=d;
      d=e;
      e=i;
      i=dp;
      dp=ep;
      ep=i;
    }
    for(i=0;i<e;i++){
      dp/=2;
      ep/=2;
    }
    if(dp==ep)i=e-d;
    else i=f-e+f-d;
    if(i<=h)printf("YES");
    else printf("NO");
}
