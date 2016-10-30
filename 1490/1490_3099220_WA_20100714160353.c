#include <stdio.h>
#include <math.h>
int main(){
    int i,r;
    long long c=0;
    scanf("%d",&r);
    for(i=0;i<r;i++)c+=(long long)(sqrt(r*r-i*i)+0.9999999999999);
    printf("%lld\n",c*4);
}
