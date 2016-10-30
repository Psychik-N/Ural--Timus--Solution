#include <stdio.h>
int main(){
long long a,b;
scanf("%I64d%I64d",&a,&b);
if((a+b)%2==0)printf("%I64d %I64d\n",a,b);
else printf("%I64d %I64d\n",b,a);
}

