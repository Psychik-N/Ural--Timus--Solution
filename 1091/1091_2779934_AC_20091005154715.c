#include <stdio.h>
int l1[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47},l2[]={6,10,14,15,21,22,26,33,34,35,38,39,46};
long long c(int a,int b){
     long long res=1,i;
     if(a<b)return 0;
     if(b>a/2)b=a-b;
     for(i=a;i>a-b;i--)res*=i;
     for(i=b;i>1;i--)res/=i;
     return res;
}
int main(){
    int i,k,s;
    long long tot=0;
    scanf("%d%d",&k,&s);
    for(i=0;i<15;i++)tot+=c(s/l1[i],k);
    for(i=0;i<13;i++)tot-=c(s/l2[i],k);
    if(tot>10000)printf("10000");
    else printf("%I64d",tot);
}
