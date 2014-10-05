#include <stdio.h>
#include <math.h>
int main(){
    int i,r;
    long long c=0;
    scanf("%d",&r);
    for(i=0;i<r;i++)c+=(long long)(sqrt((double)r*r-(double)i*i)+0.999999);
    printf("%I64d\n",c*4);
}
