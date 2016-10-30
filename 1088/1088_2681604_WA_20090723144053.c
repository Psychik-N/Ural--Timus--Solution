#include <stdio.h>
int main(){
    long long d,e,f,dp,ep,h,i;
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&d,&e,&f,&dp,&ep,&h);
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
    else i=f+f-e-d;
    if(i<=h)printf("YES");
    else printf("NO");
}

