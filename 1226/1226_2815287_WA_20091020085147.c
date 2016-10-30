#include <stdio.h>
int main(){
char stk[1010],t;
int sl=0,i;
while((t=getchar())!=EOF){
if((t>='a'&&t<='z')||(t>='A'&&t<='Z')){
stk[sl]=t;
sl++;
}else{
for(i=sl-1;i>=0;i--)putchar(stk[i]);
sl=0;
putchar(t);
}
}
}
