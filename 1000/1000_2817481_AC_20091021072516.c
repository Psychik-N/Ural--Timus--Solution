#include <stdio.h>
int main(){
int a,b;
unsigned int i;
scanf("%d%d",&a,&b);
for(i=0;i<2200000000;i++);
printf("%d",a+b);
}
