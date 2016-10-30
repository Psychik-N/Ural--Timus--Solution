#include <stdio.h>
int main(){
    int i,n,s=0;
    scanf("%d",&n);
    for(i=0;i<=n;i++)s+=(i+n)*(n-i+1)/2+i*(n-i+1);
    printf("%d\n",s);
}
