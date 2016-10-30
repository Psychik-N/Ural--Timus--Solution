#include <stdio.h>
#pragma comment(linker,"/STACK:16777216)
int main(){
    char c[10000010];
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",a+b);
}
