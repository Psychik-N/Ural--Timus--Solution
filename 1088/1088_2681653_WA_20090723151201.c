#include <stdio.h>
int max(int a,int b){
    if(a>b)return a;
    return b;
}
int abs(int a){
    if(a>=0)return a;
    return -a;
}
int main(){
    int d,e,f,dp,ep,h,i,t;
    scanf("%d %d %d %d %d %d",&d,&e,&f,&dp,&ep,&h);
    dp--;
    ep--;
    t=max(d,e);
    for(i=0;i<t;i++){
      dp/=2;
      ep/=2;
    }
    if(dp==ep)t=abs(e-d);
    else t=f-e+f-d;
    if(t<=h)printf("YES");
    else printf("NO");
}
