#include <stdio.h>
int main(){
    long long i,n,s=0;
    scanf("%I64d",&n);
    for(i=0;i<=n;i++)s+=(i+n)*(n-i+1)/2+i*(n-i+1);
    printf("%I64d\n",s);
}
