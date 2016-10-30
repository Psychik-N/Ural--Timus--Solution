#include <stdio.h>
#include <stdlib.h>
typedef long long i64;
struct Item{
    int v;
    int i;
}item[100001];
int cmp(struct Item *a,struct Item *b){
    if(a->v!=b->v)return a->v-b->v;
    return a->i-b->i;
}
int main(){
    int n,i,l,r,lp=1,rp=1,cnt;
    i64 fl=0,fr=0,tl,tr,bl,br;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&(item[i].v));
        item[i].i=i;
    }
    qsort(item+1, n, sizeof(struct Item), cmp);
    i=1;
    while(i<=n){
        l=i;
        while(i<=n&&item[i].v==item[l].v)i++;
        cnt=i-l;
        l=item[l].i;
        r=item[i-1].i;
        if(lp<=r)tl=r-lp+r-l+cnt+fl;
        else tl=lp-l+cnt+fl;
        if(rp<=r)tr=r-rp+r-l+cnt+fr;
        else tr=rp-l+cnt+fr;
        bl=tl<tr?tl:tr;
        if(lp<l)tl=r-lp+cnt+fl;
        else tl=lp-l+r-l+cnt+fl;
        if(rp<l)tr=r-rp+cnt+fr;
        else tr=rp-l+r-l+cnt+fr;
        br=tl<tr?tl:tr;
        lp=l;
        rp=r;
        fl=bl;
        fr=br;
    }
    printf("%lld\n",fl<fr?fl:fr);
    return 0;
}
