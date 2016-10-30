#include <stdio.h>
int main(){
long long a,b;
scanf("%lld%lld",&a,&b);
if((a+b)%2==0)printf("%lld %lld\n",a,b);
else printf("%lld %lld\n",b,a);
}
