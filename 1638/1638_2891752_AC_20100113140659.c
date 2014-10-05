#include<stdio.h>
int a,b,c,d;
int main(){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(c<d)printf("%d",(d-c-1)*(a+b+b)+b*2);
    else printf("%d",(c-d)*(a+b+b)+a);
    return 0;
}
