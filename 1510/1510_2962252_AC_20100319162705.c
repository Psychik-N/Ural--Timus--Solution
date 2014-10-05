#include <stdio.h>
#include <stdlib.h>
int i,n,k[1000000];
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&k[i]);
    qsort(k,n,4,cmp);
    printf("%d\n",k[n/2]);
}
