#include <stdio.h>
struct A{int a,b;}x;
struct B{char c[5];};
int main(){
x.a=1;
x.b=0;
printf("%s\n",((struct B)x).c);
}