#include <stdio.h>
#include <stdlib.h>
int min(int a,int b){
    if(a<=b)return a;
    return b;
}
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int va[110],vb[110];
int main(){
    int i,k,bv=2000000000,n,m,tv;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&va[i]);
    for(i=0;i<m;i++)scanf("%d",&vb[i]);
    qsort(va,n,4,cmp);
    qsort(vb,m,4,cmp);
    for(k=0;k<=min(n,m);k++){
      tv=0;
      for(i=0;i<n-k;i++)tv+=va[i];
      for(i=0;i<m-k;i++)tv+=vb[i]*k;
      if(tv<bv)bv=tv;
    }
    printf("%d",bv);
}
