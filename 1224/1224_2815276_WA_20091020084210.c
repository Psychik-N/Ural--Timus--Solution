#include <stdio.h>
int main(){
unsigned int a,b;
scanf("%u%u",&a,&b);
if(a>b)printf("%u\n",(b-1)*2);
else printf("%u\n",(a-1)*2+1);
}
