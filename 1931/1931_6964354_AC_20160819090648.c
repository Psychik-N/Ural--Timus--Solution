#include <stdio.h>
int v[100001],c[100001]={0};
int main(){
    int n,i,bv=0,bi=1,cp=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",v+i);
    for(i=2;i<=n;i++){
        c[cp]++;
        c[i]++;
        if(v[i]<v[cp])cp=i;
    }
    for(i=1;i<=n;i++)if(c[i]>bv){
        bv=c[i];
        bi=i;
    }
    printf("%d\n",bi);
    return 0;
}
