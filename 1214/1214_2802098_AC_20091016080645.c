#include <stdio.h>
int main(){
int a,b;
scanf("%d%d",&a,&b);
if((a<=0||b<=0)||(a+b)%2==0)printf("%d %d\n",a,b);
else printf("%d %d\n",b,a);
}


