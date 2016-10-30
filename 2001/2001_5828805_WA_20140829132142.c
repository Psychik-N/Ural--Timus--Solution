#include <stdio.h>
int main(){
int n;
char s[2][6]={"black","grimy"};
scanf("%d",&n);
puts(s[(n*(n+1)/2)%2]);
return 0;
}