#include <stdio.h>
int main(){
int a,b,c;
scanf("%d%d",&a,&b);
rewind(stdin);
scanf("%d",&c);
if(a==c)printf("%d",a+b);
else while(1);
}
