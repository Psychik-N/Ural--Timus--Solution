#include <stdio.h>
#include <stdlib.h>
int ps[33000],pe[33000],pv[33000]={0},tt[20000],tl=0,mt[20000],ml=0,cza[6000],czb[6000],czc[6000]={0};
int max(int a,int b){
    if(a>b)return a;
    return b;
}
int min(int a,int b){
    if(a<b)return a;
    return b;
}
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
void init(int p,int s,int e){
     ps[p]=s;
     pe[p]=e;
     if(s==e)return;
     init(p*2+1,s,(s+e)/2);
     init(p*2+2,(s+e)/2+1,e);
}
void change(int p,int s,int e,int v){
     if(ps[p]==s&&pe[p]==e){
       pv[p]=v;
       return;
     }
     if(s<=pe[p*2+1])change(p*2+1,s,min(e,pe[p*2+1]),v);
     if(e>=ps[p*2+2])change(p*2+2,max(s,ps[p*2+2]),e,v);
}
int query(int p,int q){
    int s;
    if(ps[p]==pe[p])return pv[p];
    if(q<=pe[p*2+1])s=query(p*2+1,q);
    else s=query(p*2+2,q);
    if((s>>1)>(pv[p]>>1))return s;
    return pv[p];
}
int bins(int x){
    int l=0,r=tl-1,m;
    while(l!=r){
      m=(l+r)>>1;
      if(tt[m]<x)l=m+1;
      else r=m;
    }
    return l;
}
int main(){
    int n,i,lst=-1,p1,p2,ts=-1,bv=-1,bs,be;
    char c;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d %d %c",&cza[i],&czb[i],&c);
      if(c=='b')czc[i]=1;
      mt[ml++]=cza[i];
      mt[ml++]=czb[i];
    }
    mt[ml++]=0;
    mt[ml++]=1000000000;
    qsort(mt,ml,4,cmp);
    for(i=0;i<ml;i++)
      if(lst!=mt[i])tt[tl++]=lst=mt[i];
    init(0,0,tl-1);
    change(0,0,tl-2,2);
    change(0,tl-1,tl-1,3);
    for(i=0;i<n;i++){
      p1=bins(cza[i]);
      p2=bins(czb[i])-1;
      change(0,p1,p2,((i+2)<<1)|czc[i]);
    }
    for(i=0;i<tl;i++)mt[i]=query(0,i)&1;
    for(i=0;i<tl;i++){
      if(mt[i]==1&&ts!=-1){
        if(tt[i]-tt[ts]>bv){
          bv=tt[i]-tt[ts];
          bs=tt[ts];
          be=tt[i];
        }
        ts=-1;
      }else if(mt[i]==0&&ts==-1)ts=i;
    }
    printf("%d %d\n",bs,be);
}
