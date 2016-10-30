#include <stdio.h>
int main(){
long long a,b;
scanf("%I64d%I64d",&a,&b);
if(a>b)printf("%I64d\n",(b-1)*2);
else printf("%I64d\n",(a-1)*2);
}
