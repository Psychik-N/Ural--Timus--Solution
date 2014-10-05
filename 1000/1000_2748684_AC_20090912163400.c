#include <stdio.h>
#pragma comment(linker,"/STACK:16777216")
int main(){
    char c[10000010];
    int a,b,i;
    for(i=0;i<10000000;i++)c[i]=1;
    scanf("%d%d",&a,&b);
    printf("%d",a+b);
}
